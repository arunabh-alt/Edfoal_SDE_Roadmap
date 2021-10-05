// Apache commons lang3 remove all types of element from the String array
import java.util.Arrays;
import org.apache.commons.lang3.ArrayUtils;
public class ArrayDeletion {

	public static void main(String[] args) {
		
		String[] str = {"3","2","2","3"};
		
		str = Arrays.stream(str).filters(s-> !s.eqauls("3")).toArray(String[] :: new);
		
		for(String s : str) {
			System.out.println(s);
		}
		

	}

}