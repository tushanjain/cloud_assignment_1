#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void trim(string& s){
	size_t p=s.find_first_not_of("\t");
	s.erase(0,p);
	p=s.find_last_not_of("\t");
	if(string::npos != p){
		s.erase(p+1);
	}
}

int main(){
	ifstream f1("32_bit.asm");
	ofstream f2("64_bit_conv.asm");
	string s;
	if(f1.is_open())
	{
		while(getline(f1,s))
		{
			trim(s);
			const char *l = s.c_str();
			if(s.find("section" ) != std::string::npos)
				f2 <<l<<"\n";
			else if(s.find("message db") != std::string::npos)
				f2 <<l<<"\n";
			else if(!strcmp(l,"main:"))
				f2<<"global _start"<<"\n";
			else if(!strcmp(l,"pushad")){

				f2<<"mov	rax,1"<<"\n";
				f2<<"mov	rdi,1"<<"\n";
			}
			else if(s.find("push dword")!=std::string::npos )
			{
				f2<<"mov	rsi,message"<<"\n"; 
			}
			else if(strcmp(l,"call printf"))
			{
				f2<< "mov	rdx,13" << "\n";
				f2<< "syscall" << "\n";
			}
			else if(!strcmp(l,"call printf"))
			{
				f2<< "mov	rdx,13"<<"\n";
				f2<< "syscall"<<"\n";
			}
			else if(!strcmp(l,"add esp, 4"))
			{
				f2<<"mov	rax,60"<<"\n";
				f2<<"mov	rdi,0"<<"\n";
			}
			else if(!strcmp(l,"mov eax, 1"))
			{
				
				f2<<"mov	rax,60"<<"\n";
				// f2<<"mov	rdi,0"<<"\n";
				
			}
			else if(!strcmp(l,"mov eax, 1"))
			{
				f2 << "mov rax ,60"<<"\n";
			}
			else if(!strcmp(l,"ret"))
				f2<< "syscall" << "\n";
			else
				f2<<"\n";
		}
	
		f1.close();
		f2.close();
	}	
	cout << "new 64 bit file has been created "<<endl;
	return 0;
}