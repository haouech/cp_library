/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Haouech
 */
public class JavaApplication2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
      Boolean c = true;
      while(c)
      {
        // Use the Scanner class
      Scanner sc = new Scanner(System.in);  
      
      int n      = sc.nextInt();        // read input as integer
      int a      = sc.nextInt();
      BigInteger res = BigInteger.valueOf(0);
      BigInteger ans = BigInteger.valueOf(a);
      for(int i=1;i<=n;i++)
      {
          ans = BigInteger.valueOf(a);
          ans=ans.pow(i);
          ans=ans.multiply(BigInteger.valueOf(i));
          res=res.add(ans);
      }
      System.out.println(res.toString());
      }
    }
    
}
