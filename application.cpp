#include <bits/stdc++.h>
using namespace std;
//#include "libxl.h"

class Charges{
private:
    double riderCharge;
    double mAeCharge;
    double fundFees;
public:
    
    Charges(double riderCharge=0,double mAeCharge=0,double fundFees=0){
        this->fundFees=fundFees;
        this->riderCharge=riderCharge;
        this->mAeCharge=mAeCharge;
    }
    double getRiderCharge(){
        return this->riderCharge;
    }
    double getmAeCharge(){
        return this->mAeCharge;
    }
    double getFundFees(){
        return this->fundFees;
    }
    void setRiderCharge(double r){
        riderCharge=r;
    }
    void setmAeCharge(double m){
        mAeCharge=m;
    }
    void setFundFees(double f){
        fundFees=f;
    }
};

class Insurance{
    private:
    double stepUpRate;
    double stepUpPeriod;
     Charges charges;
    double initialPremium;
    double startAge;
    double firstWithdrawalAge;
    double annuityCommencementAge;
    double lastDeathAge;
    double mortality;
    double withdarawalRate;
    double fundRebalancingTarget;
    double riskFreeRate;
    double volatility;

    public:
    Insurance(){}
    Insurance(double stepUpRate=0,double stepUpPeriod=0,Charges charges=NULL,double initialPremium=0, double startAge=0,double firstWithdrawalAge=0,
    double annuityCommencementAge=0,double lastDeathAge=0,double mortality=0,double withdrawalRate = 0,double fundRebalancingTarget=0,
    double riskFreeRate=0, double volatility=0){
          this->stepUpRate=stepUpRate;
          this->stepUpPeriod=stepUpPeriod;
          this->charges=charges;
          this->initialPremium=initialPremium;
          this->startAge=startAge;
          this->firstWithdrawalAge=firstWithdrawalAge;
          this->annuityCommencementAge=annuityCommencementAge;
          this->lastDeathAge=lastDeathAge;
          this->mortality=mortality;
          this->withdarawalRate=withdarawalRate;
          this->fundRebalancingTarget=fundRebalancingTarget;
          this->riskFreeRate = riskFreeRate;
          this->volatility=volatility;
    }
    
    Charges getCharges(){
        return this->charges;
    }
    void setCharges(Charges charges){
        this->charges=charges;
    }
    double getStepUpRate(){
        return this->stepUpRate;
    }
    
    double getStepUpPeriod(){
        return this->stepUpPeriod;
    }
    double getInitialPremium(){
        return this->initialPremium;
    }
    double getStartAge(){
        return this->startAge;
    }
    double getFirstWithdrawalAge(){
        return this->firstWithdrawalAge;
    }
    double getAnnuityCommencementAge(){
        return this->annuityCommencementAge;
    }
    double getLastDeathAge(){
        return this->lastDeathAge;
    }
    double getMortality(){
        return this->mortality;
    }
    double getWithdrawalRate(){
        return this->withdarawalRate;
    }
    double getFundRebalancingTarget(){
        return this->fundRebalancingTarget;
    }
    double getRiskFreeRate(){
        return this->riskFreeRate;
    }
    double getVolatility(){
        return this->volatility;
    }
    void setStepUpRate(double stepUpRate){
         this->stepUpRate = stepUpRate;
    }
    void setStepUpPeriod(double stepUpPeriod){
        this->stepUpPeriod = stepUpPeriod;
    }
    void getInitialPremium(double initialPremium){
        this->initialPremium = initialPremium;
    }
    void getStartAge(double startAge ){
        this->startAge = startAge;
    }
    void getFirstWithdrawalAge(double firstWithdrawalAge){
        this->firstWithdrawalAge = firstWithdrawalAge;
    }
    void getAnnuityCommencementAge(double annuityCommencementAge){
        this->annuityCommencementAge = annuityCommencementAge;
    }
    void getLastDeathAge(double lastDeathAge){
        this->lastDeathAge =lastDeathAge;
    }
    void getMortality(double mortality){
        this->mortality = mortality;
    }
    void getWithdrawalRate(double withdarawalRate){
        this->withdarawalRate = withdarawalRate;
    }
    void getFundRebalancingTarget(double fundRebalancingTarget){
        this->fundRebalancingTarget = fundRebalancingTarget;
    }
    void setRiskFreeRate(double riskFreeRate){
        this->riskFreeRate = riskFreeRate;
    }
    void setVolatility(double volatility){
        this->volatility=volatility;
    }

};
class MaxAnnualWithdrawal{
public :
    double age1;
    double age2;
    double age3;
    double age4;
    double rate1;double rate2;double rate3;double rate4;
    MaxAnnualWithdrawal(double age1=0,double age2=0,double age3=0,double age4=0,double rate1=0,double rate2=0,double rate3=0,double rate4=0){
        this->age1=age1;
        this->age2=age2;
        this->age3=age3;
        this->age4 = age4;
        this->rate1=rate1;
        this->rate2=rate2;
        this->rate3=rate3;
        this->rate4=rate4;
    }

};

double calculateFundsPreFee(double initialPremium,double factor){
    return factor*initialPremium;
}

double calculateAvgPreWithdrawal(double fund1,double mAecharge,double contribution=0){
    return fund1-mAecharge+contribution;
}


double calculateRiderCharge(double riderChargePercent,double avgPostWithdrawal){
    return avgPostWithdrawal*(riderChargePercent/100);
}
double calculateDF(double riskFreeRate,int year){
    double df = pow(1+riskFreeRate/100,-1*year);
    cout<<"df is "<<df<<endl;
    return df;
}
int calculaterebalanceIndicator(int withdrawalPhase,int automaticPeriodBenefitStatus){
    return withdrawalPhase+automaticPeriodBenefitStatus;
}
double calculateFund2Returns(double riskFreeRate,double volatility){
    double mean=riskFreeRate/100;
    double stddev=volatility;
    double logmean = log(1 + mean) - 0.5 * std::pow(stddev, 2);
    double logstddev = sqrt(std::log(1 + std::pow(stddev / mean, 2)));
    double norminv = sqrt(2.0) * std::erf(2.0 * std::rand() / RAND_MAX - 1.0);
    double result = exp(logmean + logstddev * norminv) - 1.0;
    //
    return result*100; // returning in %
}
int calculatelastDeath(int year,double lastDeathAge){
     int lastdeathage=(int)lastDeathAge;
     if(year==lastdeathage) return 1;
     return 0;
}
int calculateAutomaticPeriodBenefitStatus(int lastDeathAge,int year,int prevWithdrawalPhase,double prevAvgPostDeathClaims,
int prevAutoPeriodBenefitStatus=0){
    int result = (year >= lastDeathAge) ? 0 : ((prevWithdrawalPhase == 1 && (int)prevAvgPostDeathClaims == 0) ? 1 : prevAutoPeriodBenefitStatus);
    return result;
}
int calculateWithDrawalPhase(int year,double firstWithdrawalAge,double annuityCommencementAge,double prevAvgPostDeathClaims,double lastDeathAge){
    int result = (year > (int)firstWithdrawalAge || year > (int)annuityCommencementAge) && prevAvgPostDeathClaims > 0 &&
     year < (int)lastDeathAge ? 1 : 0;
     return result;
}
int calculateGrowthPhase(int year,double firstWithdrawalAge,double annuityCommencementAge,double lastDeathAge){
    int result = (year <= (int)firstWithdrawalAge && year <= (int)annuityCommencementAge && year < (int)lastDeathAge) ? 1 : 0;
    return result;
}
int calculateEligibleStepUp(int stepUpPeriod,int year,int growthPhase){
    int result = (year<=stepUpPeriod && growthPhase==1)?1:0;
    return result;
}
double calculateMaxAnnualWithdrawawlRate(int growthPhase,MaxAnnualWithdrawal mawObj,int age){
    //this function returns the percentage with first value as 0%
    double result = (growthPhase == 1) ? 0 : (age > mawObj.age4 ? mawObj.rate4 : (age > mawObj.age3 ?
     mawObj.rate3 : (age > mawObj.age2 ? mawObj.rate2 : (age > mawObj.age1 ? mawObj.rate1 : 0))));
     cout<<"Max annual withdrawal rate is "<<result<<endl;
     return result;
     //MaxAnnualWithdrawal class needs to be defined
}
double calculateMaxAnnualWithdrawal(double maxAnnualWithdrawalRate,double withdrawalBase){
    //for first year it's 0; otherwise = 
    double result = withdrawalBase*(maxAnnualWithdrawalRate/100);
    cout<<"MaxAnnual withdrawal is "<<result<<endl;
    return result;
}
double calculateCumulativeWithdrawalAmount(double currentWithdrawalAmount,double prevCumWithdrawalAmount=0){
    return currentWithdrawalAmount+prevCumWithdrawalAmount;
}
double calculateWithdrawalAmount(int withdrawalPhase,int autoPeriodBenefitStatus,double withdrawalRate,double maxAnnualWithdrawal,
double withdrawalBase){
    //here withdrawalRate is given in %age
    double result = (withdrawalPhase==1)?(withdrawalRate/100)*withdrawalBase : (autoPeriodBenefitStatus==1? maxAnnualWithdrawal:0);
    return result;
}

double calculateWithdrawalBase(int growthPhase,double avgPostDeathClaims,int eligibleStepUp,double prevWithdrawalBase,double qx,
double contribution,double stepUpRate,double riderCharge,double mAeChare){
  ///initially it's equal to initialPremium
    double max_value = 0.0;
    if (growthPhase == 1) {
        max_value = avgPostDeathClaims;
    }
    double second_value = prevWithdrawalBase * (1 - qx/100) + contribution;
    if (second_value > max_value) {
        max_value = second_value;
    }
    if (eligibleStepUp == 1) {
        double third_value = prevWithdrawalBase * (1 - qx/100) * (1 + stepUpRate/100) + contribution - mAeChare - riderCharge;
        if (third_value > max_value) {
            max_value = third_value;
        }
    }
    return max_value;
}
double calculateDeathBenefitBase(double prevDeathBenefitBase,double qx,double mAeCharges,double prevWithdrawalAmount,
double riderCharge,double contribution=0){
    //initiallyy it's equal to initialPremium
    double result = max(0.0, prevDeathBenefitBase * (1 - qx/100) + contribution - mAeCharges - prevWithdrawalAmount - riderCharge);
    cout<<"death benefit base is "<<result<<endl;
    return result;
}
double calculateNARDeathClaims(double deathPayments,double avgPostCharges){
    return max(0.0,deathPayments-avgPostCharges);
}
double calculateROPDeathBase(double prevROPdeathBase,double qx){
    //initial value = initialPremium
    return prevROPdeathBase*(1-qx/100);
}
double calculateFund2PostRebalance(double avgPostCharges,double fund1PostRebalance){
    return avgPostCharges-fund1PostRebalance;
}

double calculateFund1PostRebalance(int rebalanceIndicator,double avgPostDeathClaims,double fundRebalanceTarget,double fund1PostDeathClaims){
    double result=0;
    if (rebalanceIndicator == 1) {
    result = avgPostDeathClaims * (fundRebalanceTarget/100);
    }
    else {
    result = fund1PostDeathClaims;
    }
    return result;
}
// defining common methods for fund1 and fund2 post death claims
double calculateFundPostDeathClaims(double avgPostDeathClaims,double fundPostCharges,double avgPostCharges){
    double result;
    if (avgPostDeathClaims == 0) {
    result = 0;
    }
    else {
    result = fundPostCharges * (avgPostDeathClaims / avgPostCharges);
    }
    return result;
}

double calculateAvgPostDeathClaims(double avgPostCharges,double deathPayments){
    return max(0.0,avgPostCharges-deathPayments);
}

double calculateDeathPayments(int growthPhase,int withdrawalPhase,int autoPeriodicBenefitPhase,int lastDeath,double prevROPDeathBase,
double prevDeathBenefitBase,double qx){
    // initiallyy it's 0;
    double result;
    if(growthPhase+withdrawalPhase+autoPeriodicBenefitPhase+lastDeath==0)
    result=0;
    else
    result = max(prevDeathBenefitBase,prevROPDeathBase)*(qx/100);
    return result;
}
// defining common function for fund1 and fund2 of everytype where first argument is that value which is compared in if condition
//so use accordingly
double calculateFundValues(double avgFundValue,double corrAvgFundValue,double corrFundValue){
    double result;
    if(avgFundValue==0)
    result=0;
    else
    result = corrFundValue*(avgFundValue/corrAvgFundValue);
    return result;
}

double calculateAvgPostCharges(double avgPostWithdrawal,double riderCharge){
    return avgPostWithdrawal-riderCharge;
}
double calculateAvgPostWithdrawal(double avgPreWithdrawal,double withdrawalAmount=0){
    //initially it's equal to avgPreWithdrawal
    return max(0.0,avgPreWithdrawal-withdrawalAmount);
}

double calculateMandECharges(double mAeChargePercent,double fundFeesPercent,double avgPostDeathClaims){
    return avgPostDeathClaims*(mAeChargePercent/100+fundFeesPercent/100);
}
double calculateFundPreFee(double fundPostRebalance, double fundReturnsPercent){
    return fundPostRebalance*(1+fundReturnsPercent/100);
}
double calculateAvgPreFee(double fund1PreFee,double fund2PreFee){
    return fund1PreFee+fund2PreFee;
}
vector<double> recursiveConvergence(double avgPreWithdrawal,double riderChargeRate,double deathPayments, int growthPhase,
double prevWithdrawalBase,double qx,double contribution,int eligibleStepUp,double stepUpRate,double mAeCharge,
int withdrawalPhase,int autoPeriodBenefitStatus,double withdrawalRatePercent,double maxAnnualWithdrawalRate){
    double wa,wb,apdc,apc,rc,apw,maw;
	double wa_guess=1000;
	for(int i=0;i<1000;i++){
		apw=calculateAvgPostWithdrawal(avgPreWithdrawal,wa_guess);
        rc=calculateRiderCharge(riderChargeRate,apw);
        apc = calculateAvgPostCharges(apw,rc);
        apdc = calculateAvgPostDeathClaims(apc,deathPayments);
        //mAe=calculateMandECharges(1.4,0.15,apdc);//check the paramenters
        wb=calculateWithdrawalBase(growthPhase,apdc,eligibleStepUp,prevWithdrawalBase,qx,contribution,stepUpRate,rc,mAeCharge );
        maw=calculateMaxAnnualWithdrawal(maxAnnualWithdrawalRate,wb);
        wa=calculateWithdrawalAmount(withdrawalPhase,autoPeriodBenefitStatus,withdrawalRatePercent,maw,wb);
        if(abs(wa-wa_guess)<0.01)
        break;
        wa_guess=wa;
    }
    //cout<<wa<<" "<<wb<<" "<<apdc<<" "<<apc<<" "<<rc<<" "<<apw<<" "<<maw<<endl;
    return {apw,apc,apdc,wb,wa,maw};
}
int main(){
 cout<<"Enter the details in following order\n"
     <<"1. Step up rate\n"
     <<"2. step up period\n"
     <<"3. rider charge\n"
     <<"4. Initial Premium\n"
     <<"5. start age\n"
     <<"6. first Withdrawal age\n"
     <<"7. annuity commencement age\n"
     <<"8. last death age \n"
     <<"9. mortality\n"
     <<"10. withdrawal rate \n"
     <<"11. fixed allocation funds automatic rebalancing target \n"
     <<"12. M&E Charge \n"
     <<"13. Fund Fees\n"
     <<"14. Risk Free Rate\n";

    double stepUpRate=10, stepUpPeriod=10,riderCharge=0.85, initialPremium=100000, startAge=60,firstWithdrawalAge=70, 
    annuityCommencementAge=80, lastDeathAge=100, mortality=0.5,
     withdrawalRate=3, fundRebalancingTarget=20,mAeCharge=1.4,fundFees=0.15,riskFreeRate=3,volatility=0;

     cin>>stepUpRate>>stepUpPeriod>>riderCharge>>initialPremium>>startAge>>firstWithdrawalAge>>annuityCommencementAge>>lastDeathAge
     >>mortality>>withdrawalRate>>fundRebalancingTarget>>mAeCharge>>fundFees>>riskFreeRate>>volatility;

    cout<<"Now enter Max Annual Withdrawal ages sequencially and then their corresponding rates sequencially\n";

    double age1=59.5,age2=65,age3=76,age4=80,rate1=4,rate2=5,rate3=6,rate4=7;
    cin>>age1>>age2>>age3>>age4>>rate1>>rate2>>rate3>>rate4;
    
    MaxAnnualWithdrawal mawObj(age1,age2,age3,age4,rate1,rate2,rate3,rate4);

    Charges charges(riderCharge,mAeCharge,fundFees);

    Insurance insurance(stepUpRate,stepUpPeriod,charges,initialPremium,startAge,firstWithdrawalAge,annuityCommencementAge,lastDeathAge,
    mortality,withdrawalRate, fundRebalancingTarget,riskFreeRate,volatility); //add riskfreerate

    int n=insurance.getLastDeathAge()-insurance.getStartAge();
    double contribution=0;

    vector<double >avgPreFeeList;
    vector<double>fund1PreFeeList;
    vector<double>fund2PreFeeList;
    vector<double>mAeChargeList;
    vector<double>avgPreWithdrawalList;
    vector<double>fund1PreWithdrawalList;
    vector<double>fund2PreWithdrawalList;
    vector<double>withdrawalAmountList;
    vector<double>avgPostWithdrawalList;
    vector<double>fund1PostWithdrawalList;
    vector<double>fund2PostWithdrawalList;
    vector<double>riderChargeList;
    vector<double>avgPostChargesList;
    vector<double>fund1PostChargesList;
    vector<double>fund2PostChargesList;
    vector<double>deathPaymentsList;
    vector<double>avgPostDeathClaimsList;
    vector<double>fund1PostDeathClaimsList;
    vector<double>fund2PostDeathClaimsList;
    vector<double>fund1PostRebalanceList;
    vector<double>fund2PostRebalanceList;
    vector<double>ropDeathBaseList;
    vector<double>narDeathClaimsList;
    vector<double>deathBenefitBaseList;
    vector<double>withdrawalBaseList;
    vector<double>cumulativeWithdrawalList;
    vector<double>maxAnnualWithdrawalList;
    vector<double>maxAnnualWithdrawalRateList;
    vector<int>eligibleStepUpList;
    vector<int>growthPhaseList;
    vector<int>withdrawalPhaseList;
    vector<int>autoPeriodicBenefitStatusList;
    vector<int>lastDeathList;
    vector<double>fund1ReturnList;
    vector<double>fund2ReturnList;
    vector<int>rebalanceIndicatorList;
    vector<double>dfList;
    vector<double>qxList;
    for(int i=0;i<=insurance.getLastDeathAge()-insurance.getStartAge();i++){
        qxList.push_back(0.5);
        if(i==0){
            fund1PreFeeList.push_back(0.16*insurance.getInitialPremium());
            fund2PreFeeList.push_back(0.64*insurance.getInitialPremium());
            avgPreFeeList.push_back(calculateAvgPreFee(fund1PreFeeList[i],fund2PreFeeList[i]));
            mAeChargeList.push_back(0);
            avgPreWithdrawalList.push_back(calculateAvgPreWithdrawal(avgPreFeeList[i],mAeChargeList[i],0));
            fund1PreWithdrawalList.push_back(calculateFundValues(avgPreWithdrawalList[i],avgPreFeeList[i],fund1PreFeeList[i]));
            fund2PreWithdrawalList.push_back(calculateFundValues(avgPreWithdrawalList[i],avgPreFeeList[i],fund2PreFeeList[i]));
            withdrawalAmountList.push_back(0);
            avgPostWithdrawalList.push_back(avgPreWithdrawalList[i]);
            fund1PostWithdrawalList.push_back(calculateFundValues(avgPostWithdrawalList[i],avgPreWithdrawalList[i],fund1PreWithdrawalList[i]));
            fund2PostWithdrawalList.push_back(calculateFundValues(avgPostWithdrawalList[i],avgPreWithdrawalList[i],fund2PreWithdrawalList[i]));
            riderChargeList.push_back(0);
            avgPostChargesList.push_back(avgPostWithdrawalList[i]-riderChargeList[i]);
            fund1PostChargesList.push_back(calculateFundValues(avgPostChargesList[i],avgPostWithdrawalList[i],fund1PostWithdrawalList[i]));
            fund2PostChargesList.push_back(calculateFundValues(avgPostChargesList[i],avgPostWithdrawalList[i],fund2PostWithdrawalList[i]));
            deathPaymentsList.push_back(0);
            avgPostDeathClaimsList.push_back(calculateAvgPostDeathClaims(avgPostChargesList[i],deathPaymentsList[i]));
            fund1PostDeathClaimsList.push_back(calculateFundValues(avgPostDeathClaimsList[i],avgPostChargesList[i],fund1PostChargesList[i]));
            fund2PostDeathClaimsList.push_back(calculateFundValues(avgPostDeathClaimsList[i],avgPostChargesList[i],fund2PostChargesList[i]));
            rebalanceIndicatorList.push_back(0);

            deathBenefitBaseList.push_back(insurance.getInitialPremium());
            withdrawalBaseList.push_back(insurance.getInitialPremium());
            cumulativeWithdrawalList.push_back(0);
            maxAnnualWithdrawalList.push_back(0);
            maxAnnualWithdrawalRateList.push_back(0);
            eligibleStepUpList.push_back(0);
            growthPhaseList.push_back(0);
            withdrawalPhaseList.push_back(0);
            autoPeriodicBenefitStatusList.push_back(0);
            lastDeathList.push_back(0);
            
            fund1PostRebalanceList.push_back(calculateFund1PostRebalance(rebalanceIndicatorList[i],avgPostDeathClaimsList[i],
            insurance.getFundRebalancingTarget(),fund1PostDeathClaimsList[i]));
            fund2PostRebalanceList.push_back(calculateFund2PostRebalance(avgPostChargesList[i],fund1PostRebalanceList[i]));
            ropDeathBaseList.push_back(insurance.getInitialPremium());
            narDeathClaimsList.push_back(calculateNARDeathClaims(deathPaymentsList[i],avgPostChargesList[i]));
            fund1ReturnList.push_back(insurance.getRiskFreeRate());
            fund2ReturnList.push_back(0);
            dfList.push_back(calculateDF(insurance.getRiskFreeRate(),i));
        }
        else{
            fund1ReturnList.push_back(insurance.getRiskFreeRate());
            fund2ReturnList.push_back(calculateFund2Returns(insurance.getRiskFreeRate(),insurance.getVolatility()));
            fund1PreFeeList.push_back(calculateFundPreFee(fund1PostRebalanceList[i-1],fund1ReturnList[i]));
            fund2PreFeeList.push_back(calculateFundPreFee(fund2PostRebalanceList[i-1],fund2ReturnList[i]));
            avgPreFeeList.push_back(calculateAvgPreFee(fund1PreFeeList[i],fund2PreFeeList[i]));
            mAeChargeList.push_back(calculateMandECharges(insurance.getCharges().getmAeCharge(),
            insurance.getCharges().getFundFees(),avgPostDeathClaimsList[i-1]));
            avgPreWithdrawalList.push_back(calculateAvgPreWithdrawal(avgPreFeeList[i],mAeChargeList[i],0));
            fund1PreWithdrawalList.push_back(calculateFundValues(avgPreWithdrawalList[i],avgPreFeeList[i],fund1PreFeeList[i]));
            fund2PreWithdrawalList.push_back(calculateFundValues(avgPreWithdrawalList[i],avgPreFeeList[i],fund2PreFeeList[i]));

            withdrawalPhaseList.push_back(calculateWithDrawalPhase(insurance.getStartAge()+i,insurance.getFirstWithdrawalAge(),
            insurance.getAnnuityCommencementAge(),avgPostDeathClaimsList[i-1],insurance.getLastDeathAge()));

            autoPeriodicBenefitStatusList.push_back(calculateAutomaticPeriodBenefitStatus(insurance.getLastDeathAge(),
            insurance.getStartAge()+i,withdrawalPhaseList[i-1],avgPostDeathClaimsList[i-1],autoPeriodicBenefitStatusList[i-1]));

            growthPhaseList.push_back(calculateGrowthPhase(insurance.getStartAge()+i,insurance.getFirstWithdrawalAge(),
            insurance.getAnnuityCommencementAge(),insurance.getLastDeathAge()));
            lastDeathList.push_back(calculatelastDeath(insurance.getStartAge()+i,insurance.getLastDeathAge()));
            eligibleStepUpList.push_back(calculateEligibleStepUp(insurance.getStepUpPeriod(), i,growthPhaseList[i]));
            rebalanceIndicatorList.push_back(calculaterebalanceIndicator(withdrawalPhaseList[i],autoPeriodicBenefitStatusList[i]));
            dfList.push_back(calculateDF(insurance.getRiskFreeRate(),i));
            //qxList.push_back(0.5);

            maxAnnualWithdrawalRateList.push_back(calculateMaxAnnualWithdrawawlRate(growthPhaseList[i],mawObj,insurance.getStartAge()+i));
            deathPaymentsList.push_back(calculateDeathPayments(growthPhaseList[i],withdrawalPhaseList[i],autoPeriodicBenefitStatusList[i],
            lastDeathList[i],ropDeathBaseList[i-1],deathBenefitBaseList[i-1],qxList[i]));

            vector<double>v=recursiveConvergence(avgPreWithdrawalList[i],insurance.getCharges().getRiderCharge(),deathPaymentsList[i],
            growthPhaseList[i-1],withdrawalBaseList[i-1],qxList[i],contribution,eligibleStepUpList[i],insurance.getStepUpRate(),
            mAeChargeList[i],withdrawalPhaseList[i],autoPeriodicBenefitStatusList[i],insurance.getWithdrawalRate(),
            maxAnnualWithdrawalRateList[i]);

            withdrawalBaseList.push_back(v[3]);
            withdrawalAmountList.push_back(calculateWithdrawalAmount(withdrawalPhaseList[i],
            autoPeriodicBenefitStatusList[i],insurance.getWithdrawalRate(),maxAnnualWithdrawalList[i],withdrawalBaseList[i]));
            avgPostWithdrawalList.push_back(calculateAvgPostWithdrawal(avgPreWithdrawalList[i],withdrawalAmountList[i]));
            
            fund1PostWithdrawalList.push_back(calculateFundValues(avgPostWithdrawalList[i],avgPreWithdrawalList[i],fund1PreWithdrawalList[i]));
            fund2PostWithdrawalList.push_back(calculateFundValues(avgPostWithdrawalList[i],avgPreWithdrawalList[i],fund2PreWithdrawalList[i]));
            riderChargeList.push_back(calculateRiderCharge(insurance.getCharges().getRiderCharge(),avgPostWithdrawalList[i]));

            avgPostChargesList.push_back(calculateAvgPostCharges(avgPostWithdrawalList[i],riderChargeList[i]));

            fund1PostChargesList.push_back(calculateFundValues(avgPostChargesList[i],avgPostWithdrawalList[i],fund1PostWithdrawalList[i]));
            fund2PostChargesList.push_back(calculateFundValues(avgPostChargesList[i],avgPostWithdrawalList[i],fund2PostWithdrawalList[i]));
            
            avgPostDeathClaimsList.push_back(calculateAvgPostDeathClaims(avgPostChargesList[i],deathPaymentsList[i]));
            fund1PostDeathClaimsList.push_back(calculateFundValues(avgPostDeathClaimsList[i],avgPostChargesList[i],fund1PostChargesList[i]));
            fund2PostDeathClaimsList.push_back(calculateFundValues(avgPostDeathClaimsList[i],avgPostChargesList[i],fund2PostChargesList[i]));
           
            // withdrawalBaseList.push_back(calculateWithdrawalBase(growthPhaseList[i],avgPostDeathClaimsList[i],eligibleStepUpList[i],
            // withdrawalBaseList[i-1],qxList[i],contribution,insurance.getStepUpRate(),riderChargeList[i],mAeChargeList[i]));

            fund1PostRebalanceList.push_back(calculateFund1PostRebalance(rebalanceIndicatorList[i],avgPostDeathClaimsList[i],
            insurance.getFundRebalancingTarget(),fund1PostDeathClaimsList[i]));
            fund2PostRebalanceList.push_back(calculateFund2PostRebalance(avgPostChargesList[i],fund1PostRebalanceList[i]));
            ropDeathBaseList.push_back(calculateROPDeathBase(ropDeathBaseList[i-1],qxList[i]));
            narDeathClaimsList.push_back(calculateNARDeathClaims(deathPaymentsList[i],avgPostChargesList[i]));
            deathBenefitBaseList.push_back(calculateDeathBenefitBase(deathBenefitBaseList[i-1],qxList[i],mAeChargeList[i],
            withdrawalAmountList[i-1],riderChargeList[i],contribution));
            
            maxAnnualWithdrawalList.push_back(calculateMaxAnnualWithdrawal(maxAnnualWithdrawalRateList[i],withdrawalBaseList[i]));
            cumulativeWithdrawalList.push_back(calculateCumulativeWithdrawalAmount(withdrawalAmountList[i],cumulativeWithdrawalList[i-1]));
        }
        
    std::ofstream outfile("output.csv");

    // Write the headers to the file
    outfile << "Year" << "," << "Anniversary" <<","<< "Age"<<","<< "Contribution"<<","<< "AV Pre-Fee"<<","<< "Fund1-Pre-Fee"<<","<<
     "Fund2 Pre-Fee"<<","<< "M&E/Fund Fees"<<","<< "AV Pre-Withdrawal"<<","<< "Fund1 Pre-Withdrawal"<<","<< "Fund2 Pre-Withdrawal"<<","<<
    "Withdrawal Amount"<<","<< "AV Post-Withdrawal"<<","<< "Fund1 Post-Withdrawal"<<","<< "Fund2 Post-Withdrawal"<<","<<
     "Rider Charge"<<","<< "AV Post Charges"<<","<< "Fund1 Post-Charges"<<","<< "Fund2 Post-Charges"<<","<< "Death Payments"<<","<<
      "AV Post-Death Claims"<<","<< "Fund1 Post-Death Claims"
    <<","<<"Fund2 Post-Death Claims"<<","<<"Fund1 Post-Rebalance"<<","<<"Fund2 Post-Rebalance"<<","<<"ROP Death Base"<<","<<
    "NAR Death Claims"<<","<<"Death Benefit Base"<<","<<"Withdrawal Base"<<","<<"Withdrawal Amount"<<","<<"Cumulative Withdrawal"
    <<","<<"Max Annual Withdrawal"<<","<<"Max Annual Withdrawal Rate"<<","<<"Eligible StepUp"<<","<<"Growth Phase"<<","<<
    "AutoMatic Period Benefit Status"<<","<<"Last Death"<<","<<"Fund1 Returns"<<","<<"Fund2 Returns"<<","<<"Rebalance Indicator"
    <<","<<"DF"<<","<<"qx"<<endl;

    // Loop through the vectors and write the values to the file
    for (int i = 0; i <=n; i++) {
        outfile << i << "," << "" <<","<< insurance.getStartAge()+i<<","<< "0"<<","<< avgPreFeeList[i]<<","<< fund1PreFeeList[i]
        <<","<<fund2PreFeeList[i]<<","<< mAeChargeList[i]<<","<< avgPreWithdrawalList[i]<<","<< fund1PreWithdrawalList[i]<<","<< 
        fund2PreWithdrawalList[i]<<","<<withdrawalAmountList[i]<<","<< avgPostWithdrawalList[i]<<","<< fund1PostWithdrawalList[i]<<","
        << fund2PostWithdrawalList[i]<<","<<riderChargeList[i]<<","<< avgPostChargesList[i]<<","<< fund1PostChargesList[i]<<","<<
         fund2PostChargesList[i]<<","<< deathPaymentsList[i]<<","<<avgPostDeathClaimsList[i]<<","<< fund1PostDeathClaimsList[i]
    <<","<<fund2PostDeathClaimsList[i]<<","<<fund1PostRebalanceList[i]<<","<<fund2PostRebalanceList[i]<<","<<ropDeathBaseList[i]<<","<<
    narDeathClaimsList[i]<<","<<deathBenefitBaseList[i]<<","<<withdrawalBaseList[i]<<","<<withdrawalAmountList[i]<<","<<cumulativeWithdrawalList[i]
    <<","<<maxAnnualWithdrawalList[i]<<","<<maxAnnualWithdrawalRateList[i]<<","<<eligibleStepUpList[i]<<","<<growthPhaseList[i]<<","<<
    autoPeriodicBenefitStatusList[i]<<","<<lastDeathList[i]<<","<<fund1ReturnList[i]<<","<<fund2ReturnList[i]<<","<<rebalanceIndicatorList[i]
    <<","<<dfList[i]<<","<<qxList[i]<<endl;
    }

    // Close the output file stream
    outfile.close();
    }
    


}