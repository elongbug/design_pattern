#include <iostream>
#include "lamp.h"
#include "mixer.h"
#include "coinbox.h"
#include "billbox.h"
#include "mediator.h"
using namespace std;

int
main()
{
  Lamp lamp;
  Mixer mixer;
  CoinBox coinBox;
  BillBox billBox;

  Mediator mediator(&lamp, &mixer, &coinBox, &billBox);
  mixer.SetMediator(&mediator);
  coinBox.SetMediator(&mediator);
  billBox.SetMediator(&mediator);

  // -- 90 ���� ���� ����
  for (int i = 0; i < 90; i++)
    coinBox.InsertCoin();

  // -- ���� & ���� 
  mixer.OutOfOrder();
  coinBox.InsertCoin();
  billBox.InsertBill();
  mixer.Repair();

  billBox.InsertBill(8);
}