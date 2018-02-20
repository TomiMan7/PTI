/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pagerank;

/**
 *
 * @author tomiman
 */
public class Print {
    
       public static void printer(double[]tomb, int n)
    {
    
    	for(double s : tomb)
		//cout<<"PageRank"<<"["<<s<<"]:\t"<<endl;
                System.out.println("PageRank:["+s+"]");
    
    }
}
