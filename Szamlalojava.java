/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package szamlalojava;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author tomiman
 */
public class Szamlalojava {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {

File input = new File("/home/tomiman/prog1/2het/szamlalo.cpp");
Scanner scan = new Scanner(input);
        
int szo 	= 0;
int sor 	= 0;
int betu 	= 0;
int szam 	= 0;
int specko 	= 0;
int space       = 0;
int sum;

while(scan.hasNextLine() )
{
    String line = scan.nextLine();
    sor++;
    
    char[] ch = line.toCharArray();
    for(int i = 0; i < line.length(); i++)
    {
        if(Character.isLetter(ch[i]))
            betu++;
        
        else if(Character.isDigit(ch[i]))
                szam++;
        
        else if(Character.isSpaceChar(ch[i]))
                space++;
        else
            specko++;
    }
    String str[] = line.split((" "));
    for(int i = 0; i < str.length; i++)
        if(str[i].length() > 0)
            szo++;
}




sum = betu + szam + specko + space;

System.out.println("Ebben a fajlban ennyi sor van " + sor);
System.out.println("Ebben a fajlban ennyi szo van " + szo);
System.out.println("Ebben a fajlban ennyi betu van " + betu);
System.out.println("Ebben a fajlban ennyi szam van " + szam);
System.out.println("Ebben a fajlban ennyi space van " + space);
System.out.println("Ebben a fajlban ennyi specko/egyeb karakter van " + specko);
System.out.println("Ebben a fajlban osszesen ennyi karakter van " + sum);
    }  
}
