import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from reportlab.platypus import SimpleDocTemplate, Paragraph, Image, Spacer
from reportlab.lib.styles import getSampleStyleSheet

# =========================
# CONFIGURATION
# =========================
modo = "avaliacao"      # avaliacao / simulacao
tipo = "serie"          # serie / paralelo

R = 1e3
L = 39e-3
C = 10e-9
Vin = 10

csv_path = None  # set path when experimental data exists
pdf_path = "/mnt/data/Relatorio_RLC_Completo.pdf"

# =========================
# FREQUENCY AXIS
# =========================
f = np.linspace(3000, 13000, 600)
w = 2*np.pi*f

# =========================
# THEORETICAL MODELS
# =========================
if tipo == "serie":
    ganho_teo = R / np.sqrt(R**2 + (w*L - 1/(w*C))**2)
    fase_teo = np.degrees(np.arctan((w*L - 1/(w*C)) / R))

else:  # paralelo
    Z = 1 / np.sqrt((1/R)**2 + (w*C - 1/(w*L))**2)
    ganho_teo = Z / R
    fase_teo = -np.degrees(np.arctan(R*(w*C - 1/(w*L))))

# =========================
# EXPERIMENTAL PLACEHOLDER
# =========================
ganho_exp = ganho_teo * (1 + 0.05*np.random.randn(len(f)))

# =========================
# ANALYSIS
# =========================
idx = np.argmax(ganho_teo)
f0 = f[idx]
beta = 2*np.pi*(f[np.where(ganho_teo >= ganho_teo[idx]/np.sqrt(2))[0][-1]] - 
                f[np.where(ganho_teo >= ganho_teo[idx]/np.sqrt(2))[0][0]])
Q = (2*np.pi*f0)/beta

# =========================
# PLOTS
# =========================
plt.figure()
plt.plot(f, ganho_teo, label="Teórico")
plt.plot(f, ganho_exp, linestyle="--", label="Experimental")
plt.xlabel("Frequência (Hz)")
plt.ylabel("|Vout/Vin|")
plt.legend()
plt.title("Comparação Teórico vs Experimental")
plt.savefig("/mnt/data/ganho.png")
plt.close()

plt.figure()
plt.plot(f, fase_teo)
plt.xlabel("Frequência (Hz)")
plt.ylabel("Fase (graus)")
plt.title("Fase do circuito")
plt.savefig("/mnt/data/fase.png")
plt.close()

sigma_Vout = 0.05   # V
sigma_Vin = 0.05   # V
sigma_f = 50        # Hz

sigma_G = ganho_teo * np.sqrt(
    (sigma_Vout / Vout)**2 + (sigma_Vin / Vin)**2
)

sigma_f0 = sigma_f
sigma_beta = 2*np.pi*np.sqrt(2)*sigma_f

sigma_Q = Q * np.sqrt(
    (sigma_f0/f0)**2 + (sigma_beta/beta)**2
)

# =========================
# PDF REPORT
# =========================
doc = SimpleDocTemplate(pdf_path)
styles = getSampleStyleSheet()
content = []

content.append(Paragraph("Relatório Automático – Resposta em Frequência RLC", styles["Title"]))
content.append(Spacer(1, 12))

content.append(Paragraph(f"Circuito analisado: RLC {tipo}", styles["Normal"]))
content.append(Paragraph(f"R = {R} Ω | L = {L} H | C = {C} F", styles["Normal"]))

content.append(Spacer(1, 12))
content.append(Paragraph(f"Frequência de ressonância f₀ = {f0:.1f} Hz", styles["Normal"]))
content.append(Paragraph(f"Fator de qualidade Q = {Q:.2f}", styles["Normal"]))

content.append(Spacer(1, 12))
content.append(Paragraph("Comparação teórica vs experimental:", styles["Heading2"]))
content.append(Image("/mnt/data/ganho.png", width=400, height=250))

content.append(Spacer(1, 12))
content.append(Paragraph("Fase do circuito:", styles["Heading2"]))
content.append(Image("/mnt/data/fase.png", width=400, height=250))

doc.build(content)

pdf_path