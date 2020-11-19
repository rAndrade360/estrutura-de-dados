package binaries;

public class arvoreBinaria {
 No n;

 public No pegaIndex(No no){
 no = n;
 return no;
 }

 public No inserirNo(int valor, No no){
	 if (no!=null){
	 if (valor<no.getInfo()){
	 if (no.getEsquerda()!=null){
	 inserirNo(valor, no.getEsquerda());
	 } else {
	 no.setEsquerda(new No(valor));
	 System.out.println("NO ADCIONADO NA ESQUERDA");
	 System.out.println();
	 }
	 } else if (valor>no.getInfo()){
	 if (no.getDireita()!=null){
	 inserirNo(valor, no.getDireita());
	 } else {
	 no.setDireita(new No(valor));
	 System.out.println("NO ADCIONADO NA DIREITA");
	 System.out.println();
	 }
	 }
	 }
	 else {
	 System.out.println("NO ADICIONADO");
	 System.out.println();
	 return new No(valor);
	 }
	 return no;
	 }
 
 public boolean buscarNo(int valor, No no){
 if (no==null){
 return false;
 }
 if (valor<no.getInfo()){
 return buscarNo(valor, no.getEsquerda());
 } else if (valor>no.getInfo()) {
 return buscarNo(valor, no.getDireita());
 } else{
 return true;
 }
 }
}
