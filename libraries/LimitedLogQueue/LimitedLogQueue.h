#ifndef _LIMITEDLOGQUEUE_H 
#define _LIMITEDLOGQUEUE_H 
#include <Arduino.h> 
#include "QueueArray.h" 

 template<typename T> 
class LimitedLogQueue{  
public:  
	LimitedLogQueue(String n, int s);      
	~LimitedLogQueue();   
	void add(const T i);    
	void print();     
	float getAverage();    
private:   
	String name;   
	QueueArray<T> queue;   
	int size; 
}; 
 template<typename T> LimitedLogQueue<T>::LimitedLogQueue(String n, int s) { 
 	name = n;
	size = s;
} 

 template<typename T> LimitedLogQueue<T>::~LimitedLogQueue(){  

 } 

 template<typename T> void LimitedLogQueue<T>::add(const T i){
       if(queue.count()==size){
       queue.pop();
}
       queue.push(i);
 } 

 template<typename T> void LimitedLogQueue<T>::print(){  
	Serial.print(name);
	Serial.println(" Values:");
	int c = queue.count();
	for(int i = 0; i < c; i++){
		Serial.print(i+1);
		Serial.print(":");
		int temp = queue.pop();
		Serial.println(temp);
		queue.push(temp);
}
} 

 template<typename T> float LimitedLogQueue<T>::getAverage(){ 
	float total = 0;
	int c = queue.count();
	for(int i = 0; i < c; i++){
		int temp = queue.pop();
		total = total+temp;
	queue.push(temp);
	}
	return (float)(total/size);	
} 
 #endif 