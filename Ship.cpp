//Ship.cpp

#include "Ship.h"
#include <iostream>


Ship::Ship(){};

Ship::Ship(std::string shipStart, std::string shipOrientation, int length){ //constructor
	m_shipLength = length;
	m_hullIntegrity = length;
	m_shipHead = shipStart;
	m_shipDirection = shipOrientation;
  createArray();
}

	Ship::~Ship(){

	}

char Ship::capitalize(char column){
	if(column == 'A' || column == 'a'){
		return('A');
	}
	else if(column == 'B' || column == 'b'){
		return('B');
	}
	else if(column == 'C' || column == 'c'){
		return('C');
	}
	else if(column == 'D' || column == 'd'){
		return('D');
	}
	else if(column == 'E' || column == 'e'){
		return('E');
	}
	else if(column == 'F' || column == 'f'){
		return('F');
	}
	else if(column == 'G' || column == 'g'){
		return('G');
	}
	else if(column == 'H' || column == 'h'){
		return('H');
	}
	else if(column == 'I' || column == 'i'){
		return('I');
	}
	else if(column == 'J' || column == 'j'){
		return('J');
	}
	return('0');
}


int Ship::colToNum(std::string column){
	if(column == "A" || column == "a"){
		return(1);
	}
	else if(column == "B" || column == "b"){
		return(2);
	}
	else if(column == "C" || column == "c"){
		return(3);
	}
	else if(column == "D" || column == "d"){
		return(4);
	}
	else if(column == "E" || column == "e"){
		return(5);
	}
	else if(column == "F" || column == "f"){
		return(6);
	}
	else if(column == "G" || column == "g"){
		return(7);
	}
	else if(column == "H" || column == "h"){
		return(8);
	}
	else if(column == "I" || column == "i"){
		return(9);
	}
	else if(column == "J" || column == "j"){
		return(10);
	}
	return(0);
}

std::string Ship::numToString(int num){
	std::string temp = std::to_string(num);
	return(temp);
}

std::string Ship::numToCol(int colnum){
	if(colnum == 1){
		return("A");
	}
	else if(colnum == 2){
		return("B");
	}
	else if(colnum == 3){
		return("C");
	}
	else if(colnum == 4){
		return("D");
	}
	else if(colnum == 5){
		return("E");
	}
	else if(colnum == 6){
		return("F");
	}
	else if(colnum == 7){
		return("G");
	}
	else if(colnum == 8){
		return("H");
	}
	else if(colnum == 9){
		return("I");
	}
	else if(colnum == 10){
		return("J");
	}
	return("X");//shouldn't ever happen because validate posiiton checks for this
}

void Ship::createArray()
{
	char headcol = m_shipHead.at(0);
	char headrow= m_shipHead.at(1);
	int hrow = headrow - '0';
	std::string colstring(1,headcol);
	int hcol = colToNum(colstring);


	if(m_shipDirection=="V"||m_shipDirection=="v"){
	for(int i=0;i<m_shipLength;i++){
			m_shipArray[i]= colstring+numToString(hrow);
			hrow++;
		}
	}
	if(m_shipDirection=="H"||m_shipDirection=="h"){
	for(int i=0;i<m_shipLength;i++){
			m_shipArray[i]= (numToCol(hcol) +=headrow);
			hrow++;
		}
	}
}

std::string* Ship::getArray(){
	std::string* arrayptr = m_shipArray;
	return(arrayptr);
}


bool Ship::isDestroyed(){
	if(m_hullIntegrity == 0){
		return(true);
	}
	else{
		return(false);
	}
}

bool Ship::isHit(int row, char col){
	bool Hit=false;
	std::string hitcoords;
	char capCol= capitalize(col);
	std::string hitcol(1,capCol);
	hitcoords = hitcol + numToString(row);
	for(int i=0; i<6; i++){
		if(m_shipArray[i]==hitcoords){
			Hit=true;
			m_hullIntegrity--;
			//isDestroyed();?
		}
	}
	return(Hit);
}


void Ship::shipDocks(){
	std::cout << "\nThe head of this ship is located at : " << m_shipHead << "\n";
	std::cout << "The orientation of this ship is : " << m_shipDirection << "\n";
	std::cout << "The length of this ship is :" << m_shipLength << "\n";

	//
	for(int i = 0; i < m_shipLength; i++){

	}


}
=======
//Ship.cpp

#include "Ship.h"
#include <iostream>


Ship::Ship(){};

Ship::Ship(std::string shipStart, std::string shipOrientation, int length){ //constructor
	m_shipLength = length;
	m_hullIntegrity = length;
	m_shipHead = shipStart;
	m_shipDirection = shipOrientation;
	for(int i=0;i<6;i++){//makes sure the array never has an empty element
		m_shipArray[i] = "0";
	}
}

	Ship::~Ship(){
		
	}

int Ship::colToNum(std::string column){
	if(column == "A" || column == "a"){
		return(1);
	}
	else if(column == "B" || column == "b"){
		return(2);
	}
	else if(column == "C" || column == "c"){
		return(3);
	}
	else if(column == "D" || column == "d"){
		return(4);
	}
	else if(column == "E" || column == "e"){
		return(5);
	}
	else if(column == "F" || column == "f"){
		return(6);
	}
	else if(column == "G" || column == "g"){
		return(7);
	}
	else if(column == "H" || column == "h"){
		return(8);
	}
	else if(column == "I" || column == "i"){
		return(9);
	}
	else if(column == "J" || column == "j"){
		return(10);
	}
	return(0);
}

std::string Ship::numToString(int num){
	std::string temp = std::to_string(num);
	return(temp);
}

std::string Ship::numToCol(int colnum){
	if(colnum == 1){
		return("A");
	}
	else if(colnum == 2){
		return("B");
	}
	else if(colnum == 3){
		return("C");
	}
	else if(colnum == 4){
		return("D");
	}
	else if(colnum == 5){
		return("E");
	}
	else if(colnum == 6){
		return("F");
	}
	else if(colnum == 7){
		return("G");
	}
	else if(colnum == 8){
		return("H");
	}
	else if(colnum == 9){
		return("I");
	}
	else if(colnum == 10){
		return("J");
	}
	return("X");//shouldn't ever happen because validate posiiton checks for this
}

void Ship::createArray()
{
	char headcol = m_shipHead.at(0);
	char headrow= m_shipHead.at(1);
	int hrow = headrow - '0';
	int hcol = colToNum(std::to_string(headcol));
	std::string colstring(1,headcol);

	if(m_shipDirection=="V"){
	for(int i=0;i<m_shipLength;i++){
			hrow = hrow+i;
			m_shipArray[i]= colstring+numToString(hrow);
		}
	}
	if(m_shipDirection=="H"){
	for(int i=0;i<m_shipLength;i++){
			hcol = hcol+i;
			m_shipArray[i]= (numToCol(headcol) + headrow);
		}
	}
}

std::string* Ship::getArray(){
	std::string* arrayptr = m_shipArray;
	return(arrayptr);
}


bool Ship::isDestroyed(){
	if(m_hullIntegrity == 0){
		return(true);
	}
	else{
		return(false);
	}
}

bool Ship::isHit(int row, char col){
	bool Hit=false;
	std::string hitcoords;
	std::string hitcol(1,col);
	hitcoords = hitcol + numToString(row);
	for(int i=0; i<6; i++){
		if(m_shipArray[i]==hitcoords){
			Hit=true;
			m_hullIntegrity--;
			//isDestroyed();?
		}
	}
	return(Hit);
}


void Ship::shipDocks(){
	std::cout << "\nThe head of this ship is located at : " << m_shipHead << "\n";
	std::cout << "The orientation of this ship is : " << m_shipDirection << "\n";
	std::cout << "The length of this ship is :" << m_shipLength << "\n";

	//
	for(int i = 0; i < m_shipLength; i++){

	}


}

