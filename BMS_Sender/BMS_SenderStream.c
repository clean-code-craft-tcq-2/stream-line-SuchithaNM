#include "BMS_SenderStream.h"

float Temperature[BMS_DATA] = {};
float StateOfCharge[BMS_DATA] = {};
int senderInputValue = 0;

Bms_result (*BMSDataRead[])(float Temperature[],float StateOfCharge[])={dataread};
Bms_result(*BMSoutput[])(float Temperature[],float StateOfCharge[])={outputtoconsole};

Bms_result dataread(float Temperature[],float StateOfCharge[])
{
    float TemperatureTemp,StateOfChargeVal;
    Bms_result Status= E_NOT_OK;
    int senderInputValue = 0;
    FILE * file= fopen("./BMS_Sender/SenderInputFile.txt","r");  
    if (file) {
        for(int i=0;fscanf(file, "%f\t\t%f\n", &TemperatureTemp,&StateOfChargeVal)!=EOF ;i++)
        {
            senderInputValue=senderInputValue+1;
            Temperature[i]=TemperatureTemp;
            StateOfCharge[i]=StateOfChargeVal;
        }

        Status= E_OK;
    }
    fclose(file);
    return Status;

}


Bms_result inputvalue(BMS_inputtype inputvaluefetch)
{

    Bms_result FileRead = E_NOT_OK;
    FileRead=(*BMSDataRead[inputvaluefetch])(Temperature,StateOfCharge);
    return FileRead;


}

Bms_result outputvalue(BMS_outputtype outputvaluefetch)
{

    Bms_result Status = E_NOT_OK;
    Status=(*BMSoutput[outputvaluefetch])(Temperature,StateOfCharge);
    return Status;

}

Bms_result outputtoconsole(float Temperature[],float StateOfCharge[])
{
    for(int i=0;i<BMS_DATA;i++)
    {
        printf("Temperature value is %f and StateOfCharge value is %f\n",Temperature[i],StateOfCharge[i]);
    }
    return E_OK;


}
