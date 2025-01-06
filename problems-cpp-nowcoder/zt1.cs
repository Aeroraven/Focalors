public class Program {
    public static void Main() {
        string line;
        while ((line = System.Console.ReadLine()) != null) { // 注意 while 处理多个 case
            long a = int.Parse(line);
            long y =0;
            for(int i=line.Length-1;i>=0;i--){
                y=y*10+(line[i]-'0');
            }
            System.Console.WriteLine(a+y);
        }
    }
}