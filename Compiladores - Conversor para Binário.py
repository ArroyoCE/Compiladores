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
    return   

def armazenar_tokens(texto):
    #Usando expressões regulares separamos as palavras dos pontos e armazenamos 
    #na estrutura de dados em ordem
    padrao = re.compile(r'\w+|[^\w\s]')
    tokens = padrao.findall(texto)
    return tokens

def binario_command():
    binario(palavras)

def binario(tokens):
    print("funcionando")
    text_widget.delete(1.0, tk.END)
    
    texto_binario = ""
    controle = 0
    for token in tokens:
        if controle == 4:
            if len(token) == 1:
                if controle == 3:
                    texto_binario += "0000"
                elif controle == 1:
                    texto_binario += "00000000"
                texto_binario += format(int(token, 16), '04b')
            else:
                texto_binario += format(int(token[:-1], 16), '08b')    
               
            
            
        
        elif len(token) == 1:
            if controle == 3:
                    texto_binario += "0000"
            texto_binario += format(int(token), '04b')        
            controle = 1
        elif len(token) == 3:   
            texto_binario += str(opcode(token))
            controle = 3
            if opcode(token) == "1111":
                texto_binario += "000000000000"
                controle = 4
        elif len(token) == 2:
            texto_binario += format(int(token[:-1], 16), '04b')
            controle = 2
    print(texto_binario)
    text_widget.delete(1.0, tk.END)
    text_widget.insert(tk.END, texto_binario)
        
            

def opcode(code):
    if code == "LDA":
        return "0000"
    elif code == "ADD":
        return "0001"
    elif code == "SUB":
        return "0010"
    elif code == "OUT":
        return "1110"   
    elif code == "HLT":
        return "1111"  



# Cria a janela principal
root = tk.Tk()
root.title("Compilador SAP para binário")


text_widget = tk.Text(root, wrap='word', height=20, width=80)
text_widget.pack(expand=True, fill='both', padx=10, pady=10)
# Cria um botão para abrir o arquivo
open_button = tk.Button(root, text="Abrir Arquivo com instruções SAP", command=open_file)
open_button.pack(pady=5)

binary_button = tk.Button(root, text="Converter para Binário", command=binario_command)
binary_button.pack(pady=5)

# Cria o campo de texto para exibir o conteúdo do arquivo


# Inicia o loop principal da interface gráfica
root.mainloop()