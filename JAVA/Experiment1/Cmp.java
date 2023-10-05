public class Cmp {
	public static void main(String[] args) {
		String cr1 = args[0], cr2 = args[1];
		if (cr1.compareTo(cr2) > 0) { 
			System.out.println(args[1] + " " + args[0]);
		} 
		else {
			System.out.println(args[0] + " " + args[1]);
		}
	}
}