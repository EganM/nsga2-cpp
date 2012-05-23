#ifndef NSGA2_H_
#define NSGA2_H_

#include <nsga2/global.h>

#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

namespace nsga2 {

class NSGA2 {
public:
    NSGA2();
    virtual ~NSGA2();

    void initialize() throw (nsga2exception);
    void advance();
    void evolve();

    void set_nreal(int nreal) {
        this->nreal = nreal;
    };
    void set_nbin(int nbin) {
        this->nbin = nbin;
    };
    void set_nobj(int nobj) {
        this->nobj = nobj;
    };
    void set_ncon(int ncon) {
        this->ncon = ncon;
    };
    void set_popsize(int popsize) {
        this->popsize = popsize;
    };
    void set_ngen(int ngen) {
        this->ngen = ngen;
    };
    void set_pcross_real(double pcross_real) {
        this->pcross_real = pcross_real;
    };
    void set_pcross_bin(double pcross_bin) {
        this->pcross_bin = pcross_bin;
    };
    void set_pmut_real(double pmut_real) {
        this->pmut_real = pmut_real;
    };
    void set_pmut_bin(double pmut_bin) {
        this->pmut_bin = pmut_bin;
    };
    void set_eta_c(double eta_c) {
        this->eta_c = eta_c;
    };
    void set_eta_m(double eta_m) {
        this->eta_m = eta_m;
    };
    void set_nbits(const std::vector<int>& nbits) {
        this->nbits = nbits;
    };
    void set_limits_realvar(const std::vector< std::pair<double,double> >& limits_realvar) {
        this->limits_realvar = limits_realvar;
    };
    void set_limits_binvar(const std::vector< std::pair<double,double> >& limits_binvar) {
        this->limits_binvar = limits_binvar;
    };

private:
    // Parameters to be defined by the user
    int nreal;
    int nbin;
    int nobj;
    int ncon;
    int popsize;
    int ngen;
    double pcross_real;
    double pcross_bin;
    double pmut_real;
    double pmut_bin;
    double eta_c;
    double eta_m;
    std::vector<int> nbits;
    std::vector< std::pair<double,double> > limits_realvar;
    // std::vector<double> min_realvar;
    // std::vector<double> max_realvar;
    // double *min_binvar;
    // double *max_binvar;
    std::vector< std::pair<double,double> > limits_binvar;
    // int choice; // to be added later, maybe.
    // int obj1;
    // int obj2;
    // int obj3;
    // int angle1;
    // int angle2;
    int t;
        
private:
    void init_streams();
    void report_parameters(std::ostream& os) const;
    void report_pop(const population& pop, std::ostream& os) const;

    void selection(population& oldpop, population& newpop)
    throw (nsga2::nsga2exception) ;
    individual& tournament(individual& ind1, individual& ind2) const;
    void crossover(const individual& parent1, const individual& parent2,
                   individual& child1, individual& child2);
    void realcross(const individual& parent1, const individual& parent2,
                   individual& child1, individual& child2);
    void bincross(const individual& parent1, const individual& parent2,
                   individual& child1, individual& child2);
        
    int nbinmut;
    int nrealmut;
    int nbincross;
    int nrealcross;
    int bitlength;
    // random generator?
    std::ofstream fpt1;
    std::ofstream fpt2;
    std::ofstream fpt3;
    std::ofstream fpt4;
    std::ofstream fpt5;
    // FILE *gp;
    population* parent_pop;
    population* child_pop;
    population* mixed_pop;
};
    
}

#endif /* NSGA2_H_ */
