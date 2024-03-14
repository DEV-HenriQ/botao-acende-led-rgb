#define botao 7
#define r 2
#define b 3
#define g 4

int var = 0;
int btnclicado = 0;
int btnliberado = 0;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
  if (digitalRead(botao) == HIGH)
  {
    btnclicado = 1;
    btnliberado = 0;
  } else
  {
    btnliberado = 1;
  }

  lerBotao(var);
}

void lerBotao(int x)
{
  if (btnclicado == 1 and btnliberado == 1)
  {
    if (x == 0)
    {
      acendeR();
    }
    else
    {
      if (x == 1)
      {
        acendeG();
      }
      else
      {
        if (x == 2)
        {
          acendeB();
        }
        else
        {
          if (x == 3)
          {
            desliga();
          }
        }
      }
    }

    btnclicado = 0;
    btnliberado = 0;
  }
}

void acendeR()
{
  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  var = 1;
}

void acendeG()
{
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(b, LOW);
  var = 2;
}

void acendeB()
{
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  var = 3;
}

void desliga()
{
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  var = 0;
}