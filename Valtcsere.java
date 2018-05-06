/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package valtcsere;

/**
 *
 * @author tomiman
 */
public class Valtcsere {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int a = 47, b = 74;
        
        System.out.println("a:" + a + "   b:" + b);       
        a ^= b;       
        b ^= a;        
        a ^= b;        
        System.out.println("a:" + a + "   b:" + b);       
        
        a = 47;
        b = 74;
        System.out.println("\n");
        
        System.out.println("a:" + a + "   b:" + b); 
        a = a - b;
        b = a + b;
        a = b - a;
        System.out.println("a:" + a + "   b:" + b);
        
        a = 47;
        b = 74;
        System.out.println("\n");
        
        System.out.println("a:" + a + "   b:" + b);
        a = a * b;
        b = a / b;
        a = a / b;
        System.out.println("a:" + a + "   b:" + b);
    }
    
}
