using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
class Solution {
    static void Main(String[] args)
    {
        int n,i;
        string[] arr = Console.ReadLine().Split(' ');
        
        
        BigInteger Sum= new BigInteger(0);
        BigInteger a= new BigInteger(System.Convert.ToInt32(arr[0]));
        BigInteger b= new BigInteger(System.Convert.ToInt32(arr[1])); 
        n=System.Convert.ToInt32(arr[2]);
        
        for(i=0;i<=n-3;i++)
        {
            Sum= b*b + a;   //Tn+2= (Tn+1)*(Tn+1)+ Tn ;
            a=b; b=Sum;
        }
        Console.WriteLine(Sum);
        
    }
}