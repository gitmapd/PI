import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os

# --- 1. CONFIGURAÇÕES E CRIAÇÃO DE DADOS ---
def inicializar_dados():
    if not os.path.exists('dados.csv'):
        data = {
            'tipo': ['refracao', 'refracao', 'refracao', 'critico', 'micro'],
            'meio_1': ['ar', 'ar', 'ar', 'acrilico', 'objetiva'],
            'meio_2': ['acrilico', 'acrilico', 'acrilico', 'ar', 'ocular'],
            'n1_conhecido': [1.0, 1.0, 1.0, 1.49, 75], 
            'angulo_1': [20, 40, 60, 42.2, 150],      
            'angulo_2': [13, 25.5, 35.5, 0, 300]      
        }
        pd.DataFrame(data).to_csv('dados.csv', index=False)
        print("-> Ficheiro 'dados.csv' criado com valores de exemplo.")

# --- 2. PROCESSAMENTO E CÁLCULOS ---
def processar_experiencia():
    N_ACRILICO_TEO = 1.49
    F_OCU = 150.0 
    PONTO_PROXIMO = 250.0 

    try:
        df = pd.read_csv('dados.csv')
    except:
        print("Erro: Ficheiro 'dados.csv' não encontrado.")
        return

    print("\n" + "="*40)
    print("  RESULTADOS LABORATÓRIO T3")
    print("="*40)

    # --- LEI DE SNELL ---
    df_refr = df[df['tipo'] == 'refracao'].copy()
    if not df_refr.empty:
        x = np.sin(np.radians(df_refr['angulo_2']))
        y = df_refr['n1_conhecido'] * np.sin(np.radians(df_refr['angulo_1']))
        m, b = np.polyfit(x, y, 1) 
        
        print(f"[REFRAÇÃO]")
        print(f"Índice n2 (declive): {m:.3f}")
        print(f"Erro Relativo: {abs(m-N_ACRILICO_TEO)/N_ACRILICO_TEO*100:.2f}%")

        # Gerar Imagem para o LaTeX
        plt.figure(figsize=(7,5))
        plt.plot(x, y, 'ro', label='Dados Medidos')
        plt.plot(x, m*x + b, 'b-', label=f'Ajuste (n={m:.2f})')
        plt.xlabel('sin(θ refratado)')
        plt.ylabel('n1 * sin(θ incidente)')
        plt.legend(); plt.grid(True)
        plt.savefig('grafico_snell.png')
        print("-> Imagem 'grafico_snell.png' guardada.")

    # --- MICROSCÓPIO ---
    df_micro = df[df['tipo'] == 'micro']
    if not df_micro.empty:
        print(f"\n[MICROSCÓPIO]")
        for _, row in df_micro.iterrows():
            m_obj = row['angulo_2'] / row['angulo_1'] # di / do
            m_ocu = PONTO_PROXIMO / F_OCU
            print(f"Ampliação Obj: {m_obj:.2f}x | Ocular: {m_ocu:.2f}x")
            print(f"AMPLIAÇÃO TOTAL: {m_obj * m_ocu:.2f}x")

    plt.show()

if __name__ == "__main__":
    inicializar_dados()
    processar_experiencia()