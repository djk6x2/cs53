#include "customer.h"
#include "business.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void customer::toss(customer customers[BUS_SIZE])
{
  srand(time(NULL));

  for(int i = 0; i < BUS_SIZE; i++)
  {
    int randNum = rand() %20;

    if(hasItems(customers[i])
       && (customers[i].m_inclination != customers[randNum].m_inclination))
    {
      cout << customers[i].m_custName << " threw " << customers[i].m_purchases[0];
      cout << " at " << customers[randNum].m_custName;
      customers[i].m_happiness += 20;
      customers[randNum].m_happiness -= 5;
      customers[i].m_purchases[0] = '\0';
    }
  }

  return;
}

void customer::rob(customer customers[BUS_SIZE])
{
  for(int i = 0; i < BUS_SIZE; i++)
  {
    int randNum = rand() %21;

    if(hasItems(customer customers[randNum])
       && (customers[i].m_inclination == customers[randNum].m_inclination))
    {
      cout << customers[i].m_custName << " stole " << customers[randNum].m_purchases[0];
      cout << " from " << customers[randNum].m_custName << endl;
      customers[i].m_happiness += 25;
      customers[randNum].m_happiness -= 20;
      customers[i].m_purchases[0] = customers[randNum].m_purchases[0];
      customers[randNum].m_purchases[0] = '\0';
    }

     else
    {
      cout << customers[i].m_custName << " tried to steal from ";
      cout << customers[randNum].m_custName << " but failed" << endl;
      customers[i].m_happiness -= 5;
    }
  }
}

bool customer::hasItems(customer customer)
{
  bool set = false;

  for(int i = 0; i < CUST_SIZE; i++)
  {
    if(customer.m_purchases[i] != '\0')
    {
      set = true;
    }
  }

  return set;
}
