#include <iostream>
#include <memory>
#include <cstdint>
#include <deque>
#include <vector>

//this is working flow in quantom area.master slave model.
//compailer is down. to cant write next. i exit to write. move vc. move!!!


struct GrobalKnowleage
{
	int A;
	int B;
	int C;
};
struct MasterLocal {
	int X;
	int Y;
	int Z;
};

enum class Task {
	None=0,
	A,
	B,
	C,
};
typedef std::shared_ptr<GrobalKnowleage> SGK;
typedef std::shared_ptr<Master> SMaster;
struct Slave;

struct Master {
	SGK Know = std::make_shared<GrobalKnowleage>();
	MasterLocal ML;
	std::vector <Slave> S;

	Slave AllocSlave(Task T) {
		Slave Sl;
		S.push_back(Sl);
		Sl.SetGrobal(Know);
		Sl.T = T;
		Sl.SetMaster(std::make_shared<Master>(*this));
		return Sl;
	}

	bool Called() { return true; }

};
struct SlaveLocal {
	int XX;
	int YY;
	int ZZ;
};
struct SlaveShare {
	int AB;
	int BC;
	int CX;
};

typedef std::shared_ptr<SlaveShare> SSS;//i hope share on working for they self.
typedef std::shared_ptr<Slave> SSlavel;
struct Slave {
	int MagicA;
	int MagicB;
	int MagicC;
	SGK S = std::make_shared<GrobalKnowleage>();
	SlaveLocal SL;
	SSS SS = std::make_shared<SlaveShare>();
	Task T = Task::None;
	SMaster SM = std::make_shared<Master>();

	bool SetMaster(SMaster In) {
		SM =  In;
		return true;
	}

	bool SetGrobal(SGK In) {

		S = In;
	}
	SGK GetGroba() {
		return S;
	}
	Slave SharowCopy() {//because Quantam Region.
		return (*this);
	}
	bool SetTask(Task& In) {
		T = In;
		return true;
	}

	bool BeWork() {
		bool X;
		return X;
	}
	bool End() {
		 SM->Called();
		return true;
	}

};














int main() {
	Master M;

	auto S = M.AllocSlave(Task::A);
	auto SII = M.AllocSlave(Task::B);


	for (std::intmax_t i = 0; i < 5; i++) {
		S.BeWork();
		SII.BeWork();
	}


}
