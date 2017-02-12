#include "../../operations/operation_headers.hpp"
#include "equation.hpp"
#include <iostream>
#include <map>
#include <math.h>
#include <stdarg.h>
#include <string>
#include <vector>

duco::equation::Equation::Equation() {}

duco::equation::Equation::Equation(std::string eq) {
  eqstr = eq;
  Parse();
  SetOrder();
}

duco::equation::Equation::Equation(const Equation &copy) {
  eqstr = copy.eqstr;
  terms = copy.terms;
}

duco::equation::Equation::~Equation() { terms.clear(); }

double duco::equation::Equation::SolveEquation(
    std::vector<std::pair<std::string, double>> vals) {
  EnterVars(vals);
  return (SolveSection(0, terms.size()));
}

double duco::equation::Equation::SolveEquation(double val) {
  std::pair<std::string, double> var;
  var.second = val;
  for (int i = 0; i < terms.size(); i++) {
    if (terms[i].termtype == 3) {
      var.first = terms[i].name;
      break;
    }
  }
  return (SolveEquation({var}));
}

void duco::equation::Equation::Parse() {
  Term currentterm;
  Term add, sub, mul, divi;
  add.termtype = 2;
  add.name = "ADD";
  sub.termtype = 2;
  sub.name = "SUB";
  mul.termtype = 2;
  mul.name = "MUL";
  divi.termtype = 2;
  divi.name = "DIV";
  for (int i = 0; i < eqstr.size(); i++) {
    if (eqstr[i] == 43) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 0;
      terms.push_back(add);
    } else if (eqstr[i] == 45) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 0;
      terms.push_back(sub);
    } else if (eqstr[i] == 42) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 0;
      terms.push_back(mul);
    } else if (eqstr[i] == 47) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 0;
      terms.push_back(divi);
    } else if ((eqstr[i] >= 48 && eqstr[i] <= 57) || eqstr[i] == 46) {
      if (currentterm.termtype == 2) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        terms.push_back(mul);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 1;
      currentterm.name += eqstr[i];
    } else if (eqstr[i] >= 65 && eqstr[i] <= 90) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 2;
      currentterm.name += eqstr[i];
    } else if (eqstr[i] >= 97 && eqstr[i] <= 122) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        terms.push_back(mul);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 2) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 3;
      currentterm.name += eqstr[i];
    } else if (eqstr[i] == 40) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        terms.push_back(mul);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 2) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
        terms.push_back(mul);
      }
      currentterm.termtype = 4;
    } else if (eqstr[i] == 41) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
        currentterm.val = 0;
        currentterm.name = "";
      } else if (currentterm.termtype == 2) {
        terms.push_back(currentterm);
        currentterm.name = "";
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
        currentterm.name = "";
      }
      currentterm.termtype = 5;
    } else if (eqstr[i] == int(' ')) {
      if (currentterm.termtype == 1) {
        currentterm.val = stod(currentterm.name);
        terms.push_back(currentterm);
      } else if (currentterm.termtype == 2) {
        terms.push_back(currentterm);
      } else if (currentterm.termtype == 3) {
        terms.push_back(currentterm);
      } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
        terms.push_back(currentterm);
      }
      currentterm.termtype = 0;
      currentterm.name = "";
      currentterm.val = 0;
    }
  }
  if (currentterm.termtype == 1) {
    currentterm.val = stod(currentterm.name);
    terms.push_back(currentterm);
  } else if (currentterm.termtype == 2) {
    terms.push_back(currentterm);
  } else if (currentterm.termtype == 3) {
    terms.push_back(currentterm);
  } else if (currentterm.termtype == 4 || currentterm.termtype == 5) {
    terms.push_back(currentterm);
  }
}

void duco::equation::Equation::SetOrder() {
  std::vector<std::string> unaryops;
  for (std::map<std::string, std::function<double(double)>>::iterator it =
           unaryopmap.begin();
       it != unaryopmap.end(); ++it) {
    unaryops.push_back(it->first);
  }
  for (int i = 0; i < terms.size(); i++) {
    if (terms[i].termtype == 2) {
      for (int j = 0; j < unaryops.size(); j++) {
        if (terms[i].name == unaryops[j]) {
          terms[i].unary = true;
          break;
        }
      }
      if (terms[i].name == "MUL" || terms[i].name == "DIV") {
        terms[i].val = 3;
      } else if (terms[i].name == "ADD" || terms[i].name == "SUB") {
        terms[i].val = 4;
      }
    }
  }
}

void duco::equation::Equation::EnterVars(
    std::vector<std::pair<std::string, double>> vals) {
  for (int i = 0; i < terms.size(); i++) {
    if (terms[i].termtype == 3) {
      for (int j = 0; j < vals.size(); j++) {
        if (terms[i].name == vals[j].first) {
          terms[i].val = vals[j].second;
          break;
        }
      }
    }
  }
}

double duco::equation::Equation::SolveSection(int open, int close) {
  std::vector<Term> sectionterms;
  for (int i = open; i < close; i++) {
    if (terms[i].termtype == 4) {
      int newclose, newopen;
      i++;
      newopen = i;
      std::vector<Term> subsection;
      while (terms[i].termtype != 5 && i < close) {
        subsection.push_back(terms[i]);
        i++;
      }
      newclose = i;
      Term newterm;
      newterm.termtype = 1;
      newterm.val = SolveSection(newopen, newclose);
      sectionterms.push_back(newterm);
    } else {
      sectionterms.push_back(terms[i]);
    }
  }
  for (int n = 0; n < sectionterms.size(); n++) {
    std::cout << sectionterms[n].name << " ";
  }
  std::cout << "\n";
  for (int i = sectionterms.size() - 1; i >= 0; i--) {
    if (sectionterms[i].unary == true && sectionterms[i].termtype == 2) {
      sectionterms[i].termtype = 1;
      sectionterms[i].val =
          Operation(sectionterms[i].name, sectionterms[i + 1].val);
      sectionterms.erase(sectionterms.begin() + i + 1);
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < sectionterms.size(); j++) {
      if (sectionterms[j].val == i && sectionterms[j].termtype == 2) {
        sectionterms[j].termtype = 1;
        sectionterms[j].val =
            Operation(sectionterms[j].name, sectionterms[j - 1].val,
                      sectionterms[j + 1].val);
        sectionterms.erase(sectionterms.begin() + j + 1);
        sectionterms.erase(sectionterms.begin() + j - 1);
        j--;
      }
    }
  }
  return (sectionterms[0].val);
}

double duco::equation::Equation::Operation(std::string op, double val) {
  std::map<std::string, std::function<double(double)>>::iterator it =
      unaryopmap.find(op);
  if (it != unaryopmap.end()) {
    return (it->second(val));
  }
  return (0);
}

double duco::equation::Equation::Operation(std::string op, double val1,
                                           double val2) {
  std::map<std::string, std::function<double(double, double)>>::iterator it =
      binaryopmap.find(op);
  if (it != binaryopmap.end()) {
    return (it->second(val1, val2));
  }
  return (0);
}
