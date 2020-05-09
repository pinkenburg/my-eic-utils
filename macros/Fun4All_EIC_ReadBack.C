#pragma once

#include <fun4all/SubsysReco.h>
#include <fun4all/Fun4AllServer.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4all/Fun4AllDstInputManager.h>

#include <myeicutils/EicEventHeaderReadBack.h>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(libg4testbench.so)
R__LOAD_LIBRARY(libmyeicutils.so)

void Fun4All_EIC_ReadBack(const int nevnt = 0,
const std::string &inputfile="eic.root")
{
  Fun4AllServer *se = Fun4AllServer::instance();
  se->Verbosity(0);

  EicEventHeaderReadBack *rb = new EicEventHeaderReadBack();
  se->registerSubsystem(rb);

  Fun4AllInputManager *in = new Fun4AllDstInputManager("JADE");
  in->fileopen(inputfile);
  se->registerInputManager(in);

  se->run(nevnt);
  se->End();
  delete se;
  gSystem->Exit(0);
}
