package binaries;

import java.util.Scanner;

public class Teste {
 public static void main (String[] args){
 try (Scanner in = new Scanner (System.in)) {
	int valor;
	 int resp = 0;
	 No n = null;
	 arvoreBinaria a = new arvoreBinaria();
	
	 do{
	 System.out.println("\t MENU \t");
	 System.out.println("1 - ADCIONAR");
	 System.out.println("2 - BUSCAR");
	 System.out.println("3 - SAIR");
	 System.out.println("\nRESPOSTA: ");
	 resp = in.nextInt();
	
	 switch (resp){
	 case 1:
	 System.out.println("DIGITE O NUMERO: ");
	 valor = in.nextInt();
	 n = a.inserirNo(valor, n);
	 break;
	 case 2:
	 System.out.println("DIGITE O NUMERO: ");
	 valor = in.nextInt();
	 if (a.buscarNo(valor, n) == true){
	 System.out.println("NUMERO EXISTENTE NA ARVORE");
	 System.out.println();
	 }
	 else{
	 System.out.println("NUMERO NÃO EXISTE NA ARVORE");
	 System.out.println();
	 }
	break;
	
	 default:
	 System.out.println("OPÇÃO INVÁLIDA");
	 break;
	 }
	 }while(resp!=3);
}
 }
}