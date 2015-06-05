#ifndef SF_H
#define SF_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

class  SF{
	// Base class for implement SF 
	// this will be used by the Weight class to 
	// change the event weight 
	public:
	SF(){ syst=0; sf=1.0; err=0; label = "";}
	~SF(){}
	string label;
	double sf;
	double err;
	int syst;
	//
	virtual double get(){ return sf + err*syst ; }
};

class SF_PtEta : virtual public SF
{
	// this class implements a SF that it is pt and eta dependent (2D dependent) on something
public:
	struct range{
		double pt1; double pt2; double eta1 ; double eta2;
	};

private:
	map < range, pair<double,double> >  store;
public:
	SF_PtEta() : SF() {};
	// add to the db a sf, and error in this range [pt1,pt2) [eta1,eta2)
	virtual void add(double pt1, double pt2 , double eta1, double eta2, double sf, double err);
	// will copy the right SF and err in the mother members sf,err
	virtual void set(double pt,double eta);
};

const bool operator<( const SF_PtEta::range&r1 , const SF_PtEta::range &r2);


#endif
