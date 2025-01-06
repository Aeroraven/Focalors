public class Program {
    public static void Main() {
        string line;
        while ((line = System.Console.ReadLine()) != null) { 
            int T=int.Parse(line);
            for(int i=0;i<T;i++){
                string w = System.Console.ReadLine();
                System.Console.WriteLine((int.Parse(w)&1)==1?"NO":"YES");
            }
        }
    }
}