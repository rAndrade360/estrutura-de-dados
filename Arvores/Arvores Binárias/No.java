package binaries;

public class No {
	 private int info;
	 private No direita;
	 private No esquerda;
	 private No raiz;
	 public No getRaiz() {
	 return raiz;
	 }
	 public void setRaiz(No raiz) {
	 this.raiz = raiz;
	 }
	 public No(int info) {
	 this.info = info;
	 }
	 public int getInfo() {
	 return info;
	 }
	 public void setInfo(int info) {
	 this.info = info;
	 }
	 public No getDireita() {
	 return direita;
	 }
	 public void setDireita(No direita) {
	 this.direita = direita;
	 }
	 public No getEsquerda() {
	 return esquerda;
	 }
	 public void setEsquerda(No esquerda) {
	 this.esquerda = esquerda;
	 }
	}

