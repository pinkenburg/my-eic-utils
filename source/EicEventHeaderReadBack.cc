//____________________________________________________________________________..
#include "EicEventHeaderReadBack.h"

#include <g4main/EicEventHeader.h>

#include <fun4all/Fun4AllReturnCodes.h>

#include <phool/PHCompositeNode.h>
#include <phool/getClass.h>


using namespace std;

//____________________________________________________________________________..
EicEventHeaderReadBack::EicEventHeaderReadBack(const std::string &name):
 SubsysReco(name)
{
}

//____________________________________________________________________________..
EicEventHeaderReadBack::~EicEventHeaderReadBack()
{
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::Init(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::InitRun(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::process_event(PHCompositeNode *topNode)
{
  EicEventHeader *evthead = findNode::getClass<EicEventHeader>(topNode,"EicEventHeader");
  evthead->identify();

  if (evthead->get_eventgenerator_type() == EicEventHeader::EvtGen::milou)
  {
  cout << "trueX: " << evthead->get_milou_trueX() << endl;
  }

  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::ResetEvent(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::EndRun(const int runnumber)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::End(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EicEventHeaderReadBack::Reset(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
void EicEventHeaderReadBack::Print(const std::string &what) const
{
  cout << "EicEventHeaderReadBack::Print(const std::string &what) const Printing info for " << what << endl;
}
