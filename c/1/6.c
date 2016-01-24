#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef char(array_char_4)[4]; //定义一个数组类型 char[4]

typedef char(*array_char_4_p)[4];
//  (char[4])*   ====>  char(*)[4]
//
//  int main(void)
//  {
//
//  	int i = 0;
//
//  		char array[4] = {
//  		 'a', 'b', 'c', 'd' };
//  		 	//方法一：
//  		 		array_char_4 *p = NULL;  //根据一个数组类型， 定义一个指针。
//
//  		 			p = &array;
//
//  		 				//通过指针间接操作一个数组 
//  		 					for (i = 0; i < 4; i++) {
//
//  		 							printf("%d\n", (*p)[i]);
//  		 								}
//
//
//  		 									printf("------\n");
//
//  		 										//方法二：
//  		 											//直接定义一个 数组指针类型
//  		 												array_char_4_p p2 = NULL;
//  		 													p2 = &array;
//
//  		 														//通过指针间接操作一个数组
//  		 															for (i = 0; i < 4; i++) {
//
//  		 																	printf("%d\n", (*p2)[i]);
//  		 																		}
//
//  		 																			//方法三： 
//  		 																				//不通过typedef 直接定义个数组的指针
//  		 																					char(*p3)[4] = NULL;
//
//  		 																						p3 = &array;
//
//  		 																							for (i = 0; i < 4; i++) {
//
//  		 																									printf("%d\n", (*p3)[i]);
//  		 																										}
//
//
//
//  		 																											return 0;
//  		 																											}"")
//  		 																							}"")
//  		 															}"")"")
//  		 					}''''''''
//  		}
//  }
