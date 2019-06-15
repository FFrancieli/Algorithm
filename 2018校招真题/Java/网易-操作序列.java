/*
 * Description: 小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
 * 1、将a_i放入b序列的末尾
 * 2、逆置b序列
 * 小易需要你计算输出操作n次之后的b序列。
 * Input: 输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度。
 * 第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割。
 * Output: 在一行中输出操作n次之后的b序列,以空格分割,行末无空格。
 * SampleInput:
 * 4
 * 1 2 3 4
 * SampleOutput:
 * 4 2 1 3
 */

import java.util.*;

public class Main {
    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 5];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int index = n - 1;
        for (int i = 0; i < (n + 1) / 2; i++) {
            i == 0 ? System.out.print(a[index]) : System.out.print(" " + a[index]);
            index -= 2;
        }
        index = (n & 1) == 1 ? 1 : 0;
        for (int i = (n + 1) / 2; i < n; i++) {
            System.out.print(" " + a[index]);
            index += 2;
        }
        System.out.println();
    }
}