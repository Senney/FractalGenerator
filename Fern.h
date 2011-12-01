#ifndef FERN_H
#define FERN_H

class Fern {
public:
	// Constructor takes 3 probabilities.
	Fern(float p1, float p2, float p3);
	
	void draw(int maxpoints);
private:
	float prob1, prob2, prob3;
};

#endif
