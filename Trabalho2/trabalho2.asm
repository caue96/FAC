#Elisa Costa Lima-14/0038647
#Caue Oliveira - 	
	 .data 
  msg:   .asciiz   "\nO modulo não eh primo\n"
  msg1:  .asciiz   "\nO inverso multiplicativo eh "	

	 .text
	
	main:
	
	jal le_inteiro    #chamada de procedimento
	la  $t1,0($v0)    #carrega o valor em $v0 para $t1,aqui será o modulo
	jal le_inteiro    #chamada de procedimento
	la  $t2,0($v0)    #carrega o valor $v0 para $t2, inteiro no qual o inverso multiplicativo é demandado(numero)
	jal eh_primo	  #chamada de procedimento

	
	
	
	le_inteiro:
	
	li $v0,5         # codigo para ler um inteiro
	syscall
	jr $ra           # jumper register/return adress, retorna para o lugar o qual foi chamado
	
	
	eh_primo:
	
	#modulo em $s0
	la $s0,($t1)	# Possivel primo(n), carrega o valor em $t1 em $s0
	li $s1,2        # divisor(d),$s1 irá ser o registrador que irá guardar o "divisor" de valor 2 inicialmente
	li $s2,1        # registrador usado como refencia posteriormente
	beqz $s0,imprime_erro       # se o modulo for igual a 0, irá imprimir a msg de erro
	beq $s0,$s2, imprime_erro   # se o modulo for igual a 1 irá imprimir a msg de  erro
	li $s3,1        #(ehprimo)registrador usado para indicar se e primo ou n
	li $s4,2        #referencia para divisao a seguir
	
	loop:
	
	bne $s3,$s2,condicao       # se $s3 for diferente de 1,pula para a funçao condiçao
	div $s5,$s0,$s4            #condição n/2
	slt $s6,$s0,$s5            # se $s0<$s5,$s3 =1/  se d> n/2  
	bne $s6,$zero,condicao     # tem q ser zero o resultado, se nao pula para a função para condicao
	
	div $s6,$s0,$s1            #n/d
	mfhi $s6	           # mover o resto da divisao pra $s6
	beq $zero,$s6,condicao2    #n%d ==0
	
	condicao:
	
	bne $s3,$s2,imprime_erro   # se "eh primo" =$s3 for !=1 não é primo (confirmando se o numero é primo ou n)
	jal calc_inverso	   #chamada de procedimento
	
	condicao2:
	
	li $s3,0     		  #ehprimo==0
	addi $s1,$s1,1		  #$s1= $s1+1
	jal loop   
	
	
	calc_inverso:
	
	#reaproveitar alguns registradores $s2 ,$s4,$s6
	#em $s0 está o modulo
	la $s2,($t2)     #carrega o "numero" de $t2 em $s2, o numero no qual o inverso multiplicativo é requisitado
	la $s6,($s0)	 # copia do numero primo em outro registrador
	loop2:
	subi $s6,$s6,1    #s6 = $s6 -1 ,possivel inverso multiplicativo e resposta do programa 
	mul  $s4,$s6,$s2  # multiplicação: possiveis restos do primo x numero
	div $s4,$s4,$s0   # dividir para pegar o resto em hi  $s4%$s0
	mfhi $s4          #mover o resto para $s4
	beq $s4,$s3,imprime_saida    #se $s4=$s3=1, imprime saida
	jal loop2   
	
	
	
	
		
	imprime_erro:
	
	li $v0,4      # codigo para ler imprimir uma  string
	la $a0,msg
	syscall
	jal fim	      # pula para a funcao fim
	
	imprime_saida:
	li $v0,4      #codigo para imprimir uma string
	la $a0,msg1
	syscall
	
	
	li $v0,1   #codigo para imprimir um inteiro
	la $a0,($s6)  # passar o valor em $s6 para $a0
	syscall
	jal fim
	
	
	fim:
	li $v0,10    #codigo para encerrar o programa
	syscall