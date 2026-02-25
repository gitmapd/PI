import os
import subprocess
import sys

# Tenta importar as bibliotecas, se não conseguir, instala-as sozinho
try:
    import pandas as pd
    import numpy as np
    import matplotlib.pyplot as plt
except ImportError:
    print("A instalar bibliotecas necessárias... aguarda um momento.")
    subprocess.check_call([sys.executable, "-m", "pip", "install", "pandas", "numpy", "matplotlib"])
    import pandas as pd
    import numpy as np
    import matplotlib.pyplot as plt

def executar_tudo():
    # 1. CRIAR OS DADOS (se não existirem)
    data = {
        'tipo': ['refracao', 'refracao', 'refracao', 'critico', 'micro'],
        'n1_conhecido': [1.0, 1.0, 1.0, 1.49, 75], 
        'angulo_1': [20, 40, 60, 42.2, 150],      
        'angulo_2': [13, 25.5, 35.5, 0, 300]      
    }
    df = pd.DataFrame(data)
    df.to_csv('dados.csv', index=False)

    # 2. CÁLCULOS
    refr = df[df['tipo'] == 'refracao']
    x = np.sin(np.radians(refr['angulo_2']))
    y = refr['n1_conhecido'] * np.sin(np.radians(refr['angulo_1']))
    m, b = np.polyfit(x, y, 1)

    # 3. GERAR GRÁFICO (guarda o ficheiro png)
    plt.figure(figsize=(8, 6))
    plt.scatter(x, y, color='red', label='Dados')
    plt.plot(x, m*x + b, color='blue', label=f'Ajuste n={m:.3f}')
    plt.xlabel('sin(theta2)')
    plt.ylabel('n1 * sin(theta1)')
    plt.grid(True)
    plt.savefig('grafico_snell.png') 
    
    # 4. CRIAR FICHEIRO DE TEXTO COM OS RESULTADOS
    with open('RESULTADOS_RELATORIO.txt', 'w', encoding='utf-8') as f:
        f.write("=== RESULTADOS PARA O RELATÓRIO ===\n\n")
        f.write(f"1. ÍNDICE DE REFRAÇÃO (n2): {m:.3f}\n")
        f.write(f"2. ERRO RELATIVO: {abs(m-1.49)/1.49*100:.2f}%\n")
        f.write(f"3. AMPLIAÇÃO MICROSCÓPIO: {(300/150)*(250/150):.2f}x\n\n")
        f.write("Verifica a pasta do script! Deves ter lá:\n")
        f.write("- grafico_snell.png (Usa no LaTeX)\n")
        f.write("- dados.csv (Os teus dados)\n")

    print("\nSUCESSO!")
    print("1. O gráfico foi guardado como 'grafico_snell.png'")
    print("2. Os cálculos foram guardados em 'RESULTADOS_RELATORIO.txt'")
    print(f"O teu índice n2 é: {m:.3f}")

if __name__ == "__main__":
    executar_tudo()
