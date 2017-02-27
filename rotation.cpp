//(cx,cy) le centre de rotation et angle en radian

PT rotate_point(double cx,double cy,double angle,PT p)
{
	double s = sin(angle);
	double c = cos(angle);

// translate point back to origin:
	p.x -= cx;
	p.y -= cy;

// counter clockwise
//  double xnew = p.x * c - p.y * s;
//  double ynew = p.x * s + p.y * c;


//clockwise
double xnew = p.x * c + p.y * s;
double ynew = -p.x * s + p.y * c;


// translate point back:
	p.x = xnew + cx;
	p.y = ynew + cy;
	return p;
}


