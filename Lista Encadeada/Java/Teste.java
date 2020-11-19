package stack;

import java.util.Scanner;

public class Teste {
	public static void main(String[] args) {
		 // TODO code application logic here
		 int resp;
		 String num;
		 int position;
		 @SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		 List list = new List();

		 do {
		 System.out.println("\tMENU\t");
		 System.out.println("1 - ADICIONAR NO INICIO");
		 System.out.println("2 - ADICIONAR NO MEIO");
		 System.out.println("3 - ADICNIONAR NO FIM");
		 System.out.println("4 - REMOVER NO INICIO");
		 System.out.println("5 - REMOVER NO MEIO");
		 System.out.println("6 - REMOVER NO FIM");
		 System.out.println("7 - IMPRIMIR LISTA");
		 System.out.println("8 - BUSCAR DE ELEMENTO POR POSICAO");
		 System.out.println("9- SAIR");
		 System.out.println("\nRESPOSTA: ");
		 resp = scan.nextInt();

		 switch (resp) {
		 case 1: System.out.print("DIGITE O ELEMENTO: \n");
		 num = scan.next();
		 list.insertAtTheBeginning(num);
		 break;
		 case 2: System.out.print("DIGITE O ELEMENTO: \n");
		 num = scan.next();
		 System.out.print("DIGITE A POSIÇÃO: \n");
		 position = scan.nextInt();
	
		 list.insertInTheMiddle(num, position);
		 break;
		 case 3: System.out.print("DIGITE O ELEMENTO: \n");
		 num = scan.next();

		 list.insertAtTheEnd(num);
		 break;
		 case 4: list.removeFromTheBeginning();;
		 break;
		 case 5: System.out.println("DIGITE A POSICAO DESEJADA:");
		 position = scan.nextInt();
		 list.removeFromTheMiddle(position);
		 break;
		 case 6: list.removeFromTheEnd();;
		 break;
		 case 7: list.printList();;
		 break;
		 case 8: if (list.emptyList() == false){
		 System.out.println("DIGITE A POSICAO: ");
		 position = scan.nextInt();
		 list.getByPosition(position);
		 break;
		 }
		 else {
		 System.out.println("LISTA VAZIA");
		 break;
		 }
		 default: System.out.println("OPÇÃO INVÁLIDA");

		 }

		 }while(resp != 9);
		 }

		}
