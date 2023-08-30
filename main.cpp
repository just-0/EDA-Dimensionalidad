#include<iostream>
#include<vector>
#include<random>
#include<math.h>
#include<fstream>
#include<string>

using namespace std;


int main()
{
	for(int d: {10,50,100,500,1000} )
	{

    		vector<vector<float>> points(100,vector<float> (d,-1));//Vector que almacena los puntos


    		std::random_device rd;
    		std::mt19937 gen(rd());
    		std::uniform_real_distribution<> dis(0, 1);
        	for (int i = 0; i < 100; i++)
    		{
        		for (int j = 0; j < d; j++)points[i][j] = dis(gen);//Generar los puntos en todas las dimensiones
    		}


    		std::ofstream archivo(to_string(d) + ".txt", std::ios::out | std::ios::app);

    		int counter = 0;// Simplemente para saber la cantidad de distancias calculadas(4950 es lo correcto)
    		for (int i = 0; i < 100; i++)
    		{
        		for (int j = i+1; j < 100; j++)
        		{

            			double DE = 0;
            			for (int k = 0; k < d; k++)
            			{
                			DE = DE + pow(points[i][k] - points[j][k], 2);

            			}
            			counter++;
            			cout <<counter << " - " << sqrt(DE) << endl;
            			archivo << sqrt(DE) <<endl;//Escribir en el txt

        		}
    		}
		archivo.close();
	}
}
