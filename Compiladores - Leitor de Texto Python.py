import tkinter as tk
from tkinter import filedialog
import chardet
import re

# Estrutura de dados para armazenar as palavras
palavras = []

def open_file():
    global palavras
    # Abre uma caixa de diálogo para selecionar o arquivo
    file_path = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt")])
    if not file_path:
        return
    
    # Limpa o conteúdo atual do campo de texto
    text_widget.delete(1.0, tk.END)
    
    # Detecta a codificação do arquivo
    with open(file_path, 'rb') as file:
        raw_data = file.read()
        result = chardet.detect(raw_data)
        encoding = result['encoding']

    # Lê o conteúdo do arquivo e insere no campo de texto
    with open(file_path, 'r', encoding = encoding) as file:
        conteudo = file.read()
        text_widget.insert(tk.END, conteudo)

    palavras = armazenar_tokens(conteudo)
    print(palavras)   

def armazenar_tokens(texto):
    #Usando expressões regulares separamos as palavras dos pontos e armazenamos 
    #na estrutura de dados em ordem
    padrao = re.compile(r'\w+|[^\w\s]')
    tokens = padrao.findall(texto)
    return tokens

# Cria a janela principal
root = tk.Tk()
root.title("Visualizador de Arquivo de Texto")

# Cria um botão para abrir o arquivo
open_button = tk.Button(root, text="Abrir Arquivo", command=open_file)
open_button.pack(pady=10)

# Cria o campo de texto para exibir o conteúdo do arquivo
text_widget = tk.Text(root, wrap='word', height=20, width=80)
text_widget.pack(expand=True, fill='both', padx=10, pady=10)

# Inicia o loop principal da interface gráfica
root.mainloop()