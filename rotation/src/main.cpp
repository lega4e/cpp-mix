#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include <nvx/SFML/Line.hpp>
#include <nvx/Stopwatch.hpp>


using namespace nvx;
using namespace sf;
using namespace std;





// global objects
RenderWindow window;
VideoMode vmode = VideoMode::getDesktopMode();
char const *TITLE = "Application";
unsigned int FRAMERATE_LIMIT = 60u;

constexpr float const ROTATE_SPEED = 0.5f; // rad/sec





// init
void init_window()
{
	window.create(vmode, TITLE, Style::None);
	window.setPosition({0u, 0u});
	window.setFramerateLimit(FRAMERATE_LIMIT);
	return;
}

void draw_figure(RenderTarget &target, PointF const *points, int n, Line<> &line)
{
	for (int i = 0; i < n-1; ++i)
	{
		line.pos(points[i], points[i+1]);
		target.draw(line);
	}

	return;
}

inline PointF transform(PointF a, PointF x, PointF y)
{
	return { x.x*a.x + y.x*a.y, x.y*a.x + y.y*a.y };
}





// main
int main( int argc, char *argv[] )
{
	init_window();

	int const N = 13;
	Vector2f const figure[N] = {
		{ 0,   1 }, { 0, 2 }, { 1,   2 },
		{ 1,   3 }, { 2, 3 }, { 2,   2 },
		{ 4,   2 }, { 4, 1 }, { 2,   1 },
		{ 1.5, 0 }, { 1, 1 }, { 0.5, 0 },
		{ 0, 1 },
	};

	float fi = 0.f;
	bool fichanged = true;

	PointF points[N];

	Line line;
	line.color(Color::Black);
	line.thick(3.f);

	float time;
	stopwatch_t watch;
	watch.start();
	Event event;
	while(window.isOpen())
	{
		time = watch.pause().seconds();
		watch.reset().start();

		while(window.pollEvent(event))
		{

			switch(event.type)
			{
			case Event::KeyPressed:

				switch(event.key.code)
				{
				case Keyboard::C:
					window.close();
					break;
				case Keyboard::Right:
					fi -= ROTATE_SPEED * time;
					fichanged = true;
					break;
				case Keyboard::Left:
					fi += ROTATE_SPEED * time;
					fichanged = true;
				default:
					break;
				}
				break;

			default:
				break;
			}

		}


		// update
		if (fichanged)
		{
			fichanged = false;

			PointD const x = { cos(fi), cos(M_PI/2 + fi) };
			PointD const y = { sin(fi), sin(M_PI/2 + fi) };
			for (int i = 0; i < N; ++i)
			{
				points[i] = transform({
					500.f + figure[i].x * 100.f,
					500.f + figure[i].y * 100.f
				}, x, y);
			}
		}

		window.clear(Color::White);
		draw_figure(window, points, N, line);
		window.display();
	}

	return 0;
}





// end
