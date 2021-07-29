// SPPR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Decision.h"

void printVec(std::vector<int>& v, int i)
{

    std::cout << "Criterion " << i << '\t';


    for (int k=0; k < v.size(); k++)
    {
        std::cout << v[k] << " ";
    }
    std::cout << std::endl;
}

void printResult(int *v, std::string *s)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << s[i] << '\t' << v[i] << '\n';
    }
}


int main()
{
    int const n = 9, m = 9, k=9;

    std::string nameGames[n] = { "Lineage 2", "World of Warcraft", "Perfect World", "Aion", "Blade and Soul", "ArcheAge", "Skyforge", "Black Desert", "Lost Ark" };
    std::string nameGames2[n];
    int matCriter1[n][m] = { {0,1,1,1,1,1,1,1,1},{ 0,0,0,0,0,1,0,1,0},{0,1,0,1,1,1,1,1,1},{0,1,0,0,1,1,1,1,1},{ 0,0,0,0,0,1,0,1,1},{0,0,0,0,0,0,0,0,0},{ 0,0,0,0,1,1,0,1,1},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,1,0 } };
    int matCriter2[n][m] = { {0,0,1,0,0,0,0,0,0},{ 1,0,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0},{1,1,1,0,0,0,1,0,0},{ 1,1,1,1,0,0,1,0,1},{1,1,1,1,1,0,1,0,1},{ 1,1,1,0,1,0,0,0,0},{1,1,1,1,1,1,1,0,1},{1,1,1,1,1,0,1,0,0 } };
    int matCriter3[n][m] = { {0,0,0,0,0,0,1,0,0},{ 1,0,1,1,1,1,1,1,1},{1,0,0,1,0,0,1,0,1},{1,0,1,0,0,0,1,0,1},{ 1,1,1,1,0,0,1,1,1},{1,0,1,1,1,0,1,1,1},{ 1,0,0,0,0,0,0,0,0},{1,0,1,1,0,0,1,0,1},{1,0,1,1,0,0,1,0,0 } };
    int matCriter4[n][m] = { {0,1,1,1,0,0,1,0,1},{ 0,0,1,1,0,0,1,1,1},{0,0,0,0,0,0,1,0,1},{0,0,1,0,0,0,1,0,1},{ 1,1,1,1,0,0,1,0,1},{1,1,1,1,1,0,1,1,1},{ 0,0,0,0,0,0,0,0,1},{1,0,1,1,1,0,1,0,1},{0,0,0,0,0,0,1,0,0 } };
    int matCriter5[n][m] = { {0,0,0,0,0,0,0,0,1},{ 1,0,1,1,0,0,0,0,1},{1,1,0,1,0,0,0,0,1},{1,1,1,0,0,0,0,0,1},{ 1,1,1,1,0,1,1,1,1},{1,1,1,1,0,0,1,0,1},{ 1,1,1,1,0,1,0,0,1},{1,1,1,1,1,1,1,0,1},{1,0,0,0,0,0,1,0,0 } };
    int matCriter6[n][m] = { {0,1,1,1,1,0,1,1,1},{ 0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},{ 0,1,1,1,0,0,0,0,0},{1,1,1,1,1,0,1,1,1},{ 0,1,1,1,1,0,0,0,1},{0,1,1,1,1,0,1,0,1},{0,1,1,1,1,0,0,0,0 } };

    for (int i = 0; i < n; i++) 
    {
        nameGames2[i] = nameGames[i];
    }

    std::cout << "Name Game and his number\n--------------------\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "Number " << i + 1 << "\t---->\t" << nameGames[i] << '\n';
    }

    //////////////////////МЕХАНИЗМ ДОМИНИРОВАНИЯ////////////////////////

    std::vector<int> rezDomin1 = Domination(matCriter1);
    std::vector<int> rezDomin2 = Domination(matCriter2);
    std::vector<int> rezDomin3 = Domination(matCriter3);
    std::vector<int> rezDomin4 = Domination(matCriter4);
    std::vector<int> rezDomin5 = Domination(matCriter5);
    std::vector<int> rezDomin6 = Domination(matCriter6);
   
    
    std::cout << "\nMehanizm Domination\n" << "--------------------\n";
    
    printVec(rezDomin1,1);
    printVec(rezDomin2,2);
    printVec(rezDomin3,3);
    printVec(rezDomin4,4);
    printVec(rezDomin5,5);
    printVec(rezDomin6,6);

    std::cout << "\nResults Mehanizm Domination\n" << "--------------------\n";
    std::cout << "Lineage 2 = 1;\nWorld of Warcraft = 1;\nPerfect World = 0;\nAion = 0;\nBlade and Soul = 1;\nArcheAge = 2;\nSkyforge = 0;\nBlack Desert = 2;\nLost Ark = 0\n--------------------\n";


    std::vector<int> rezBlock1 = Blocking(matCriter1);
    std::vector<int> rezBlock2 = Blocking(matCriter2);
    std::vector<int> rezBlock3 = Blocking(matCriter3);
    std::vector<int> rezBlock4 = Blocking(matCriter4);
    std::vector<int> rezBlock5 = Blocking(matCriter5);
    std::vector<int> rezBlock6 = Blocking(matCriter6);


  ///////////////////////////МЕХАНИЗМ БЛОКИРОВАНИЯ////////////////////////

    std::cout << "\nMehanizm Blocking\n" << "--------------------\n";

    printVec(rezBlock1,1);
    printVec(rezBlock2,2);
    printVec(rezBlock3,3);
    printVec(rezBlock4,4);
    printVec(rezBlock5,5);
    printVec(rezBlock6,6);

    std::cout << "\nResults Mehanizm Blocking\n" << "--------------------\n";
    std::cout << "Lineage 2 = 1;\nWorld of Warcraft = 0;\nPerfect World = 0;\nAion = 0;\nBlade and Soul = 0;\nArcheAge = 2;\nSkyforge = 0;\nBlack Desert = 1;\nLost Ark = 0\n--------------------\n";
  
    //////////////////////////ТУРНИРНЫЙ МЕХАНИЗМ//////////////////////////////
    std::cout << "\nMehanizm Tournament\n" << "Matrix--------------------\n";
    
    double vesKoeff[6] = { 0.3,0.3,0.1,0.1,0.15,0.05 };
    double vecTour1[n] = { 0 };
    double vecTour2[n] = { 0 };
    double vecTour3[n] = { 0 };
    double vecTour4[n] = { 0 };
    double vecTour5[n] = { 0 };
    double vecTour6[n] = { 0 };
    
    Tournament(matCriter1,vecTour1);
    Tournament(matCriter2,vecTour2);
    Tournament(matCriter3,vecTour3);
    Tournament(matCriter4,vecTour4);
    Tournament(matCriter5,vecTour5);
    Tournament(matCriter6,vecTour6);
    


    for (int r = 0; r < n; r++)
        std::cout << vecTour1[r] << '\t' << vecTour2[r] << '\t' << vecTour3[r] << '\t' 
                  << vecTour4[r] << '\t' << vecTour5[r] << '\t' << vecTour6[r] << '\n';
    
    std::cout << "\nWeighted matrix\n________________________\n";

    double vecWeightTour1[n] = { 0 };
    double vecWeightTour2[n] = { 0 };
    double vecWeightTour3[n] = { 0 };
    double vecWeightTour4[n] = { 0 };
    double vecWeightTour5[n] = { 0 };
    double vecWeightTour6[n] = { 0 };

    for (int i = 0; i < n; i++)
    {
        vecWeightTour1[i] = vecTour1[i] * vesKoeff[0];
        vecWeightTour2[i] = vecTour2[i] * vesKoeff[1];
        vecWeightTour3[i] = vecTour3[i] * vesKoeff[2];
        vecWeightTour4[i] = vecTour4[i] * vesKoeff[3];
        vecWeightTour5[i] = vecTour5[i] * vesKoeff[4];
        vecWeightTour6[i] = vecTour6[i] * vesKoeff[5];
    }

    for (int r = 0; r < n; r++)
        std::cout << vecWeightTour1[r] << '\t' << vecWeightTour2[r] << '\t' << vecWeightTour3[r] << '\t'
                  << vecWeightTour4[r] << '\t' << vecWeightTour5[r] << '\t' << vecWeightTour6[r] << '\n';
    
    std::cout << "\nResult\n________________________\n";

    double vecResult[n] = { 0 };

    for (int i = 0; i < n; i++)
    {
        vecResult[i] = vecWeightTour1[i] + vecWeightTour2[i] + vecWeightTour3[i] + vecWeightTour4[i] + vecWeightTour5[i] + vecWeightTour6[i];
    }

    for (int r = 0; r < n; r++)
        std::cout << vecResult[r] <<"\t----->\t"<< nameGames[r] << '\n';

    std::cout << "\nSort\n________________________\n";
    bool swap;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            swap = false;
            if (vecResult[j] < vecResult[j + 1])
            {
                swap = true;
            }
            else if (vecResult[j] == vecResult[j + 1])
            {
                if (nameGames[j] > nameGames[j + 1])
                {
                    swap = true;
                }
                else if (nameGames[j] == nameGames[j + 1])
                    swap = true;
            }
            if (swap)
            {
                std::string tmp_s    = nameGames[j + 1];
                nameGames[j + 1]     = nameGames[j];
                nameGames[j]         = tmp_s;

                double tmp_v         = vecResult[j + 1];
                vecResult[j + 1]     = vecResult[j];
                vecResult[j]         = tmp_v;

            }
        }
    }

    for (int r = 0; r < n; r++)
        std::cout << r + 1 << ".\t" << vecResult[r] << "\t----->\t" << nameGames[r] << '\n';


    /////////////////////////МЕХАНИЗМ К-МАКСИМАЛЬНЫХ////////////////////////////////
    std::cout << "\nMehanizm K-max\n" << "--------------------\n";
    int k1_m[n] = { 0 };
    int k2_m[n] = { 0 };
    int k3_m[n] = { 0 };
    int k4_m[n] = { 0 };

    int k2_4_max_opt[n] = { 0 };

    k_max(matCriter1, 0);
    k_max(matCriter2, 1);
    k_max(matCriter3, 2);
    k_max(matCriter4, 3);
    k_max(matCriter5, 4);
    k_max(matCriter6, 5);

    for (int k = 0; k < N; k++)
    {
        std::cout << "\nCriter " << k + 1 << '\n';
        for (int i = 0; i < N; i++)
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << "\t" << '\t';
            for (int j = 0; j < 4; j++)
            {
                std::cout << k_max_mat[k][i][j] << '\t';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    for (int k = 0; k < 6; k++)
    {
        std::cout << "\nCriter " << k + 1 << '\n';

        int j = 0;
        int p = 100;
        int q = 100;
        int r = 100;
        int s = 100;
        int t = 100;
        int u = 100;

        for (int m = 0; m < 4; m++)
        {
            if (m == 0)
            {
                for (int i = 0; i < N; i++)
                {
                    if (k_max_mat[k][i][j] == 9 && p == 100)
                    {
                        std::cout << "K1-max: " << nameGames2[i] << ",";
                        k1_m[i] += 1;
                        p = i;
                    }
                    if (k_max_mat[k][i][j] == 9 && p !=i)
                    {
                        std::cout  << nameGames2[i] << ",";
                        k1_m[i] += 1;
                        p = 1;
                    }
                }
                std::cout << '\n';
            }
            if (m == 1)
            {
                for (int i = 0; i < N; i++)
                {
                    if (k_max_mat[k][i][j] == 9 && q == 100)
                    {
                        std::cout << "K2-max: " << nameGames2[i] << ",";
                        k2_m[i] += 1;
                        q = i;
                    }
                    if (k_max_mat[k][i][j] == 9 && q != i)
                    {
                        std::cout  << nameGames2[i] << ",";
                        k2_m[i] += 1;
                        q = 1;
                    }
                }
                std::cout << '\n';
            }
            if (m == 2)
            {
                for (int i = 0; i < N; i++)
                {
                    if (k_max_mat[k][i][j] == 9 && r == 100)
                    {
                        std::cout << "K3-max: " << nameGames2[i] << ",";
                        k3_m[i] += 1;
                        r = i;
                    }
                    if (k_max_mat[k][i][j] == 9 && r != i)
                    {
                        std::cout  << nameGames2[i] << ",";
                        k3_m[i] += 1;
                        r = 1;
                    }
                }
                std::cout << '\n';
            }
            if (m == 3)
            {
                for (int i = 0; i < N; i++)
                {
                    if (k_max_mat[k][i][j] == 9 && s == 100)
                    {
                        std::cout << "K4-max: " << nameGames2[i] << ",";
                        k4_m[i] += 1;
                        s = i;
                    }
                    if (k_max_mat[k][i][j] == 9 && s != i)
                    {
                        std::cout  << nameGames2[i] << ",";
                        k4_m[i] += 1;
                        s = 1;
                    }
                }
                std::cout << '\n';
            }

            if (m == 3)
            {
                for (int i = 0; i < N; i++)
                {
                    if (k_max_mat[k][i][j] == 9 && t == 100)
                    {
                        std::cout << "Option 'MAX' K1 and K3 -> " << nameGames2[i] << ",";
                        t = i;
                    }
                    if (k_max_mat[k][i][j] == 9 && t != i)
                    {
                        std::cout << nameGames2[i] << ",";
                        t = 1;
                    }
                }
                std::cout << '\n';
            }
            if (m == 3)
            {
                for (int i = 0; i < N; i++)
                {
                    if (k_max_mat[k][i][j] == 8 && u == 100)
                    {
                        std::cout << "Option 'STRICTLY MAX' K2 and K4 -> " << nameGames2[i] << ",";
                        k2_4_max_opt[i] += 1;
                        u = i;
                    }
                    if (k_max_mat[k][i][j] == 8 && u != i)
                    {
                        std::cout << nameGames2[i] << ",";
                        k2_4_max_opt[i] += 1;
                        u = 1;
                    }
                }
                if (u == 100)
                {
                    std::cout << "Option 'STRICTLY MAX' K2 and K4 absent!!!" << '\n';
                }
                std::cout << '\n';
            }
            
        }
    }

    std::cout << "\nTable K-max" << '\n';

    for (int i = 0; i < N; i++)
    {
        if (i == 4 || i == 8)
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << '\t' << k1_m[i] << '\t' << k2_m[i] << '\t' << k3_m[i] << '\t' << k4_m[i] << '\n';
        }
        else
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << '\t' << k1_m[i] << '\t' << k2_m[i] << '\t' << k3_m[i] << '\t' << k4_m[i] << '\n';
        }
    }
    std::cout << '\n';

    for (int i = 0; i < N; i++)
    {
        if (i == 4 || i == 8)
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << "Option  K1 and K3" << std::resetiosflags(std::ios_base::left) << std::setw(10) << k1_m[i] << '\n';
        }
        else
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << "Option  K1 and K3" << std::resetiosflags(std::ios_base::left) << std::setw(10) << k1_m[i] << '\n';
        }
    }
    std::cout << '\n';

    for (int i = 0; i < N; i++)
    {
        if (i == 4 || i == 8)
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << "Option  K2 and K4" << std::resetiosflags(std::ios_base::left) << std::setw(10) << k2_4_max_opt[i] << '\n';
        }
        else
        {
            std::cout << std::left << std::setw(20) << nameGames2[i] << "Option  K2 and K4" <<std::resetiosflags(std::ios_base::left) << std::setw(10) << k2_4_max_opt[i] << '\n';
        }
    }
    std::cout << '\n';

    return 0;
}
   
   

   

