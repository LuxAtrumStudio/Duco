#include "../../constant.hpp"
#include "trigonometry.hpp"
#include <cmath>
#include <iostream>
#include <pessum.h>

double duco::operation::trigonometry::ConvertAngle(double angle,
                                                   bool todegree) {
  if (todegree == false) {
    return (angle * (pi / 180.0));
  } else if (todegree == true) {
    return (angle * (180.0 / pi));
  }
  return (angle);
}

double duco::operation::trigonometry::Sin(double angle, bool degree) {
  if (degree == true) {
    angle = ConvertAngle(angle);
  }
  return (sin(angle));
}

double duco::operation::trigonometry::Cos(double angle, bool degree) {
  if (degree == true) {
    angle = ConvertAngle(angle);
  }
  return (cos(angle));
}

double duco::operation::trigonometry::Tan(double angle, bool degree) {
  if (degree == true) {
    angle = ConvertAngle(angle);
  }
  return (tan(angle));
}

double duco::operation::trigonometry::Cot(double angle, bool degree) {
  if (degree == true) {
    angle = ConvertAngle(angle);
  }
  return (1.0 / tan(angle));
}

double duco::operation::trigonometry::Sec(double angle, bool degree) {
  if (degree == true) {
    angle = ConvertAngle(angle);
  }
  return (1.0 / cos(angle));
}

double duco::operation::trigonometry::Csc(double angle, bool degree) {
  if (degree == true) {
    angle = ConvertAngle(angle);
  }
  return (1.0 / sin(angle));
}

double duco::operation::trigonometry::ArcSin(double val, bool degree) {
  val = asin(val);
  if (degree == true) {
    val = ConvertAngle(val, true);
  }
  return (val);
}

double duco::operation::trigonometry::ArcCos(double val, bool degree) {
  val = acos(val);
  if (degree == true) {
    val = ConvertAngle(val, true);
  }
  return (val);
}

double duco::operation::trigonometry::ArcTan(double val, bool degree) {
  val = atan(val);
  if (degree == true) {
    val = ConvertAngle(val, true);
  }
  return (val);
}

double duco::operation::trigonometry::ArcCot(double val, bool degree) {
  val = 1.0 / atan(val);
  if (degree == true) {
    val = ConvertAngle(val, true);
  }
  return (val);
}

double duco::operation::trigonometry::ArcSec(double val, bool degree) {
  val = 1.0 / acos(val);
  if (degree == true) {
    val = ConvertAngle(val, true);
  }
  return (val);
}

double duco::operation::trigonometry::ArcCsc(double val, bool degree) {
  val = 1.0 / asin(val);
  if (degree == true) {
    val = ConvertAngle(val, true);
  }
  return (val);
}

double duco::operation::trigonometry::Los(double a, double anglea, double b,
                                          double angleb, bool degree) {
  int solvefor = -1;
  if (a == -1) {
    solvefor = 0;
  }
  if (anglea == -1) {
    if (solvefor != -1) {
      pessum::logging::Log("warning",
                           "Law of Sines cannot solve for multiple variables",
                           "duc/ope/tri", "Los");
    } else {
      solvefor = 1;
    }
  }
  if (b == -1) {
    if (solvefor != -1) {
      pessum::logging::Log("warning",
                           "Law of Sines cannot solve for multiple variables",
                           "duc/ope/tri", "Los");
    } else {
      solvefor = 2;
    }
  }
  if (angleb == -1) {
    if (solvefor != -1) {
      pessum::logging::Log("warning",
                           "Law of Sines cannot solve for multiple variables",
                           "duc/ope/tri", "Los");
    } else {
      solvefor = 3;
    }
  }
  if (degree == true) {
    anglea = ConvertAngle(anglea);
    angleb = ConvertAngle(angleb);
  }
  if (solvefor == 0) {
    return (sin(anglea) * (b / sin(angleb)));
  } else if (solvefor == 1) {
    return (asin((a * sin(angleb)) / b));
  } else if (solvefor == 2) {
    return (sin(angleb) * (a / sin(anglea)));
  } else if (solvefor == 3) {
    return (asin((b * sin(anglea)) / a));
  }
  return (a);
}

double duco::operation::trigonometry::Loc(double a, double b, double c,
                                          double anglec, bool degree) {
  int solvefor = -1;
  if (a == -1) {
    solvefor = 0;
  }
  if (b == -1) {
    if (solvefor != -1) {
      pessum::logging::Log("warning",
                           "Law of Cosines cannot solve for multiple variables",
                           "duc/ope/tri", "Loc");
    } else {
      solvefor = 1;
    }
  }
  if (c == -1) {
    if (solvefor != -1) {
      pessum::logging::Log("warning",
                           "Law of Cosines cannot solve for multiple variables",
                           "duc/ope/tri", "Loc");
    } else {
      solvefor = 2;
    }
  }
  if (anglec == -1) {
    if (solvefor != -1) {
      pessum::logging::Log("warning",
                           "Law of Cosines cannot solve for multiple variables",
                           "duc/ope/tri", "Loc");
    } else {
      solvefor = 3;
    }
  }
  if (degree == true) {
    anglec = ConvertAngle(anglec);
  }
  if (solvefor == 0) {
    return ((b * cos(anglec)) +
            sqrt(pow(c, 2) - (pow(b, 2) * pow(sin(anglec), 2))));
  } else if (solvefor == 1) {
    return ((a * cos(anglec)) +
            sqrt(pow(c, 2) - (pow(a, 2) * pow(sin(anglec), 2))));
  } else if (solvefor == 2) {
    return (sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(anglec))));
  } else if (solvefor == 3) {
    anglec = acos((pow(c, 2) - pow(a, 2) - pow(b, 2)) / (-2 * a * b));
    if (degree == true) {
      anglec = ConvertAngle(anglec, true);
    }
    return (anglec);
  }
  return (a);
}

double duco::operation::trigonometry::Lot(double a, double anglea, double b,
                                          double angleb, bool degree) {
  int solvefor = -1;
  if (a == -1) {
    solvefor = 0;
  }
  if (anglea == -1) {
    if (solvefor != -1) {
      pessum::logging::Log(
          "warning", "Law of Tangents cannot solve for multiple variables",
          "duc/ope/tri", "Lot");
    } else {
      solvefor = 1;
    }
  }
  if (b == -1) {
    if (solvefor != -1) {
      pessum::logging::Log(
          "warning", "Law of Tangents cannot solve for multiple variables",
          "duc/ope/tri", "Lot");
    } else {
      solvefor = 2;
    }
  }
  if (angleb == -1) {
    if (solvefor != -1) {
      pessum::logging::Log(
          "warning", "Law of Tangents cannot solve for multiple variables",
          "duc/ope/tri", "Lot");
    } else {
      solvefor = 3;
    }
  }
  if (degree == true) {
    anglea = ConvertAngle(anglea);
    angleb = ConvertAngle(angleb);
  }
  if (solvefor == 0) {
    return (
        (b * (tan(0.5 * (anglea - angleb)) + tan(0.5 * (anglea + angleb)))) /
        (tan(0.5 * (anglea + angleb)) - tan(0.5 * (anglea - angleb))));
  } else if (solvefor == 2) {
    return (
        (a * (tan(0.5 * (angleb - anglea)) + tan(0.5 * (angleb + anglea)))) /
        (tan(0.5 * (angleb + anglea)) - tan(0.5 * (angleb - anglea))));
  } else if (solvefor == 1) {
    pessum::logging::Log(
        "c", "Using law of tangents to solve for angles is not yet supported",
        "duc/ope/tri", "Lot");
  } else if (solvefor == 3) {
    pessum::logging::Log(
        "c", "Using law of tangents to solve for angles is not yet supported",
        "duc/ope/tri", "Lot");
  }
  return (a);
}
