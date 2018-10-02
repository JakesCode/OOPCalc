#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

struct CalculatorKey
{
	Vector2f rect;
	int value;

    CalculatorKey(Vector2f Rect, int Value)
	{
		rect = Rect;
		value = Value;
	}
};

int main()
{
	RenderWindow w(VideoMode(600, 720), "OOP Calculator");

	Font f;
	f.loadFromFile("arial.ttf");

	Text XYDebug;
	XYDebug.setFont(f);

	Text calculatorDisplay;
	calculatorDisplay.setFont(f);
	calculatorDisplay.setFillColor(Color::Black);
	calculatorDisplay.setPosition(Vector2f(125, 163));

	Text multiplySign;
	multiplySign.setFont(f);
	multiplySign.setCharacterSize(20);
	multiplySign.setString("X");
	multiplySign.setFillColor(Color::Black);
	multiplySign.setPosition(Vector2f(474, 198));

	Texture calculator;
	calculator.loadFromFile("calc.png");

	Sprite calc;
	calc.setTexture(calculator);
	calc.setPosition(Vector2f(-53, 20));

	vector<CalculatorKey> keys {
		CalculatorKey(Vector2f(125, 545), 0),
		CalculatorKey(Vector2f(315, 449), 1),
		CalculatorKey(Vector2f(220, 449), 2),
		CalculatorKey(Vector2f(125, 449), 3),
		CalculatorKey(Vector2f(125, 353), 4),
		CalculatorKey(Vector2f(220, 353), 5),
		CalculatorKey(Vector2f(315, 353), 6),
		CalculatorKey(Vector2f(125, 253), 7),
		CalculatorKey(Vector2f(220, 253), 8),
		CalculatorKey(Vector2f(315, 253), 9),
		CalculatorKey(Vector2f(408, 353), -1), // Multiply //
		CalculatorKey(Vector2f(315, 545), -2), // Equals //
	};

	string screenDisplay = "";
	bool multiplyQueued = false;

	int number1;
	int number2;

	while (w.isOpen())
	{
		w.clear(Color(50, 50, 50));
		w.draw(calc);

		Event e;
		while (w.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				w.close();
			}

			if (e.type == Event::MouseButtonPressed)
			{
				if (Mouse::isButtonPressed(Mouse::Button::Left))
				{
					for (int key = 0; key < size(keys); key++)
					{
						if (Mouse::getPosition(w).x >= keys[key].rect.x && Mouse::getPosition(w).x <= keys[key].rect.x + 80 &&
							Mouse::getPosition(w).y >= keys[key].rect.y && Mouse::getPosition(w).y <= keys[key].rect.y + 80)
						{
							cout << keys[key].value;
							cout << multiplyQueued;

							if (keys[key].value >= 0 && keys[key].value <= 9) // Buttons 0-9 //
							{
								screenDisplay += to_string(keys[key].value);
								calculatorDisplay.setString(screenDisplay);
							}
							else if (keys[key].value == -1) // Multiply //
							{
								if (screenDisplay != "")
								{
									if (!multiplyQueued)
									{
										number1 = stoi(screenDisplay);
										screenDisplay = "";
										calculatorDisplay.setString(screenDisplay);
										multiplyQueued = true;
									}
								}
							}
							else if (keys[key].value == -2) // Equals //
							{
								if (screenDisplay != "")
								{
									number2 = stoi(screenDisplay);
									screenDisplay = to_string((number1 * number2));
									calculatorDisplay.setString(screenDisplay);
									multiplyQueued = false;
								}
							}
						 
						}
					}
				}
			}
		}

		if (multiplyQueued)
		{
			w.draw(multiplySign);
		}


		XYDebug.setString("X: " + to_string(Mouse::getPosition(w).x) + "\nY: " + to_string(Mouse::getPosition(w).y));
		w.draw(XYDebug);

		w.draw(calculatorDisplay);

		w.display();
	}

	return 0;
}