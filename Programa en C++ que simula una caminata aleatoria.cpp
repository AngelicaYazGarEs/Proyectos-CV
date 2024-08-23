//GARCÍA ESCOBAR ANGÉLICA YAZMÍN
//SIMULACIÓN I
#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
using std:: cout;
using std:: cin;
using namespace std;

unsigned long int a = 16538103;
unsigned long int m = 536870;
unsigned long int s = 1;
	
vector<unsigned long int> v={1, 432003, 57371, 382923, 262245, 473851, 394489, 368403, 239471, 278161, 87157, 21951, 87049, 
73317, 71439, 31447, 430785, 46797, 365001, 73303, 465837, 286383, 394597, 317037, 255081, 320031, 264681, 494999, 415741, 
228183, 2661, 48353, 356653, 101521, 305173, 260829, 289013, 472607, 426107, 46771, 407193, 299167, 518625, 355983, 54329, 
30943, 148215, 197205, 303571, 268525, 473477, 430533, 173947, 419617, 64841, 108179, 378861, 73955, 260451, 214951, 165951, 
27219, 477873, 482499, 37335, 213877, 79593, 490533, 195581, 463565, 239591, 42131, 180311, 193039, 284049, 407119, 6275, 
523961, 58291, 512699, 270173, 473729, 303383, 119331, 428079, 422499, 15701, 162633, 179013, 518775, 195163, 289223, 454911, 
152207, 210005, 360337, 215749, 211917, 48775, 118823, 28107};

void sUniforme(){
	s=v[int(time(NULL))%int( v.size() )];
}

double Uniforme01(){
	static unsigned long int z=s;
	z*=a;
	z%=m;
	if( z==0 )
		return 1.0/m;

	return double(z)/m;
}

int main(){
	sUniforme();
	double U, p;
	float pn, ps, pe, po; //probabilidades para cada dirección
	int i, n, N=0, S=0, E=0, O=0; //N:pasos al norte(arriba), S:pasos al sur(abajo), E:pasos al este(derecha), O:pasos al oeste(izquierda)
	cout<<"Indique la cantidad de pasos que se darán"<<endl;
	cin>>n;
	cout<<"Indique la probabilidad de ir hacia arriba"<<endl;
	cin>>pn;
	cout<<"Indique la probabilidad de ir hacia abajo"<<endl;
	cin>>ps;
	cout<<"Indique la probabilidad de ir hacia derecha"<<endl;
	cin>>pe;
	cout<<"Indique la probabilidad de ir hacia izquierda"<<endl;
	cin>>po;
	for(i=0; i<n; i++){
		U = Uniforme01();
		if(U <= pn){
			N += 1;
			cout<<"Paso hacia arriba"<<endl;
		}
		else if(U > pn && U <= (pn+ps)){
			S += 1;
			cout<<"Paso hacia abajo"<<endl;
		}
		else if(U > (pn+ps) && U <= (pn+ps+pe)){
			E += 1;
			cout<<"Paso hacia derecha"<<endl;
		}
		else if(U > (pn+ps+pe) && U < 1){
			O += 1;
			cout<<"Paso hacia izquierda"<<endl;
		}
	}
	cout<<"Total de pasos"<<endl;
	cout << "Arriba= " << N << endl;
	cout << "Abajo= " << S << endl;
	cout << "Derecha= " << E << endl;
	cout << "Izquierda= " << O << endl;
return 0;
}
