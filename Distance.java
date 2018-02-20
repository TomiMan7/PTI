/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pagerank;

import static java.lang.Math.sqrt;

/**
 *
 * @author tomiman
 */
public class Distance {
    
public static double distance(double[] PR, double[] PRv, int n)
{

double osszeg = 0.0;

	for(int i = 0; i < n; i++)
		osszeg += (PRv[i] - PR[i]) * (PRv[i] - PR[i]);

return sqrt(osszeg);
}

}
