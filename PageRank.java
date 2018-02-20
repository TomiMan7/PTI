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
public class PageRank {

    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
double[] PR = {0.0, 0.0, 0.0, 0.0};
double[] PRv = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};
double[][] L = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 /3.0, 0.0}
		  };       
       
        for(;;)
{

	for(int i = 0; i < 4; i++)
	{
		PR[i] = 0.0;
			for(int j = 0; j < 4; j++)
				PR[i] += (L[i][j] * PRv[j]);

	}
	
	if (Distance.distance(PR,PRv, 4) < 0.0000000001)
		break;

	for(int i = 0; i < 4; i++)
		PRv[i] = PR[i];
}

Print.printer(PR, 4);
        
    }
    
}
