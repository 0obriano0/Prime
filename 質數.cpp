#include <stdio.h>
#include <math.h>
#include <unistd.h> 
#include <time.h> //只是想要順便計算一下時間 
#include <process.h> //多執行續函式庫

bool prime(unsigned int Num2);

int main(){
	unsigned int Num1;
	while(1){
		printf("請輸入一個值:");
		scanf("%u",&Num1);									//如果要用double就要使用 %lf 來抓取變數值 unsingned int 要用 %u 
		/*printf("質數有:2");
		for(int LoopNum1 = 3; LoopNum1 <= Num1 ; LoopNum1+=2){    	//自動產生 3 ~ 使用者輸入的值，偶數因為一定有 2 為因數，為了加快判定我全部都產生奇數。 
			if(prime(LoopNum1))										//判定是否為質數，是就輸出 
				printf(",%d",LoopNum1);
		}*/
		/*if(prime(Num1))									//判定是否為質數，是就輸出 
				printf("是質數");
		else(unsigned int)
				printf("不是質數");*/
		for(unsigned int LoopNum1 = Num1; LoopNum1 >= 2 ; LoopNum1--){    	//自動產生 3 ~ 使用者輸入的值，偶數因為一定有 2 為因數，為了加快判定我全部都產生奇數。 
			if(prime(LoopNum1)){								//判定是否為質數，是就輸出 
				printf(",%u",LoopNum1);
				break;
			}
		}
		system("pause");
	}
	return 0;
}

bool prime(unsigned int Num2){
	bool realNum = true;
	for(unsigned int LoopNum2 = 2; LoopNum2 <= sqrt(Num2) ; LoopNum2++)	//我會用根號是因為 兩兩相乘最大就是2次方了所以取根號即可少掉很多判定
		if(Num2 % LoopNum2 == 0){								//開始判定。只要可以除盡就判定不是質數，就會馬上跳出迴圈  
			realNum = false;
			break;
		}
	return realNum;
}


void displayProgress(int progress){  
        int k = 0;  
        for (k=0; k<106; k++)  
                putchar('\b');										//清除游標在的那一行，用來作為進度條顯示進度  
        int j = 0;
        fprintf(stderr,"  進度: ");
        for (j=0; j<progress/2; j++)  
                putchar('>');										//進度完成的部分用">"來表示 
        for (j=1; j<=50-progress/2; j++)  
                putchar('-');										//進度未完成的部分用"="來表示
        fprintf(stdout, "  %3d%%",progress);  
        fflush(stdout);
}
