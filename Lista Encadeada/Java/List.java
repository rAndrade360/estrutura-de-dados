package stack;

public class List{
	private No start;
	private int size;
	
	public List() {
		this.size = 0;
		this.start = null;
	}
	
	private No getNode(int position) {
		if(position < 0 && position >= this.size) {
			throw new IllegalArgumentException("Não existe");
		}else {
			No node = this.start;
			for(int i=0; i<position; i++) {
				node = node.getNext();
			}
			return node;
		}
	}
	
	public void getByPosition(int position) {
		if(position < 0 && position >= this.size) {
			System.out.println("A posição indicada não existe.");
		}else {
			No node = this.start;
			for(int i=0; i<position; i++) {
				node = node.getNext();
			}
			System.out.println("O elemento na posição "+position+" é o elemento "+node.getInfo());
		}
	}
	
	public void printList() {
		No node = null;
		for(node = this.start; node!=null; node=node.getNext()) {
			System.out.println(node.getInfo());
			System.out.println(">>");
		}
	}
	
	public void insertAtTheBeginning(Object value){
		No node = new No(value);
		node.setNext(this.start);
		this.start = node;
		if(this.size == 0) {
		}
		this.size++;
	}
	
	public void insertAtTheEnd(Object value){
		if(this.size == 0) {
			this.insertAtTheBeginning(value);
		}else {
			No node = new No(value);
			No current = this.start;
			
			for(int i=1; i<this.size; i++) {
				current = current.getNext();
			}
			current.setNext(node);
			this.size++;
		}
	}
	
	public void insertInTheMiddle(Object value, int position){
		if(this.size == 0) {
			this.insertAtTheBeginning(value);
		}else if(this.size == position){
			this.insertAtTheEnd(value);
		}else {
			No current = this.getNode(position-1);
			No node = new No(current.getNext(), value);
			current.setNext(node);
			
			this.size++;
		}
	}
	
	public void removeFromTheBeginning() {
		if(this.emptyList()) {
			throw new IllegalArgumentException("Posição não existe");
		}
		this.start = this.start.getNext();
		this.size--;
		if(this.emptyList()) {
		}
	}
	
	public void removeFromTheEnd() {
		if(this.emptyList()) {
			throw new IllegalArgumentException("Posição não existe");
		}	
		No node = this.start;
		No previous = null;
		for(int i=1; i < this.size; i++) {
			previous = node;
			node = node.getNext();
		}
		node.setNext(null);
		previous.setNext(null);
		
		this.size--;
		if(this.emptyList()) {
		}
	}
	
	public void removeFromTheMiddle(int position) {
		if(this.emptyList()) {
			throw new IllegalArgumentException("Posição não existe");
		}else if(this.size == 1) {
			this.removeFromTheBeginning();
		}else {
			No node = this.start;
			No previous = null;
			for(int i=1; i < position; i++) {
				previous = node;
				node = node.getNext();
			}
			previous.setNext(node.getNext());
			
			this.size--;
			if(this.emptyList()) {
			}
		}
		
	}
	
	public Object getValueFirstNode() {
		return this.start.getInfo();
	}
	
	public int getSize(){
		return this.size;
	}
	
	public boolean emptyList() {
		if(this.size == 0) {
			return true;
		}
		return false;
	}
	
	
	
}
