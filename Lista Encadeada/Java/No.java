package stack;

public class No {
	private No next;
	private No previous;
	private Object info;
	
	public No(No next, Object info) {
		this.setNext(next);
		this.setInfo(info);
	}
	
	public No (Object info){
		this.setInfo(info);
		this.next = null;
		this.previous = null;
	}
	
	public void setInfo(Object info) {
		this.info = info;
	}
	public Object getInfo() {
		return this.info;
	}
	
	public void setNext(No no) {
		this.next = no;
	}
	public No getNext() {
		return this.next;
	}
	public void setPrevious(No no) {
		this.previous = no;
	}
	public No getPrevious() {
		return this.previous;
	}
}
