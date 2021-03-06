; +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
; Programa teste para testar assembler
; Feito por: José Henrique Felipetto, Tiago Paiva e Pedro Gusso
; Disciplina: Tópicos avançados em arquitetura de computadores
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


MOV [4000],9
MOV [4001],12
MOV AX,[4000]
MOV BX,[4001]

;Endereco: 12
CMP AX,BX
JZ 22
JL 29
JG 41

NOP
; Se for Igual (Endereco:22)
MOV [4002],AX
OUT AX
HALT
NOP
; Se for Menor (Endereco: 29)
MOV CX,BX
SUB CX,AX
MOV BX,CX
JMP 12
NOP
; Se for Maior (Endereco: 41)
SUB AX,BX
JMP 12
NOP

HALT

; FIM
