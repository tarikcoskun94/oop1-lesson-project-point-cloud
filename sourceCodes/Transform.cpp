#include"Transform.h"
#include<iomanip>

/**
* \brief <h2><b><i>Default Constructur.</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametrelere gore yapilan constructor.</p>
*
* \param angles: Eigen::Vector3d.
* \param trans: Eigen::Vector3d.
* \param transMatrix: Eigen::Matrix4d.
*
*/
Transform::Transform() {

	trans << 0, 0, 0;
	angles << 0, 0, 0;
	transMatrix << 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;

	
}
/**
* \brief <h2><b><i>getTransMatrix fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;transMatrix in getter fonksiyonu.</p>
*
* \return transMatrix: Eigen::Matrix4d.
*
*/
Eigen::Matrix4d Transform::getTransMatrix() {

	return transMatrix;
}
/**
* \brief <h2><b><i>setAnglesX fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;angles degerlerine deger atar.</p>
*
* \param x:
*
*/
void Transform::setAnglesX(double x) {

	angles(0) = x;
	
}
/**
* \brief <h2><b><i>setAnglesY fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;angles degerlerine deger atar.</p>
*
* \param y:
*
*/
void Transform::setAnglesY(double y) {

	angles(1) = y;
}
/**
* \brief <h2><b><i>setAnglesZ fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;angles degerlerine deger atar.</p>
*
* \param z:
*
*/
void Transform::setAnglesZ(double z) {

	angles(2) = z;
}
/**
* \brief <h2><b><i>getAnglesX fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;x degiskenini dondurur</p>
*
* \return angles(0)
*/
double Transform::getAnglesX() {

	return angles(0);

}
/**
* \brief <h2><b><i>getAnglesY fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;y degiskenini dondurur</p>
*
* \return angles(1)
*/
double Transform::getAnglesY() {

	return angles(1);

}
/**
* \brief <h2><b><i>getAnglesZ fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;z degiskenini dondurur</p>
*
* \return angles(2)
*/
double Transform::getAnglesZ() {

	return angles(2);

}
/**
* \brief <h2><b><i>setTransX fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;trans degerlerine deger atar.</p>
*
* \param x:
*
*/
void Transform::setTransX(double x) {

	trans(0) = x;

}
/**
* \brief <h2><b><i>setTransY fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;trans degerlerine deger atar.</p>
*
* \param y:
*
*/
void Transform::setTransY(double y) {

	trans(1) = y;
}
/**
* \brief <h2><b><i>setTransZ fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;trans degerlerine deger atar.</p>
*
* \param Z:
*
*/
void Transform::setTransZ(double z) {

	trans(2) = z;
}
/**
* \brief <h2><b><i>getTransX fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;x degiskenini dondurur</p>
*
* \return trans(0)
*/
double Transform::getTransX() {

	return trans(0);

}
/**
* \brief <h2><b><i>getTransY fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;y degiskenini dondurur</p>
*
* \return trans(1)
*/
double Transform::getTransY() {

	return trans(1);

}
/**
* \brief <h2><b><i>getTransZ fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;z degiskenini dondurur</p>
*
* \return trans(2)
*/
double Transform::getTransZ() {

	return trans(2);

}
/**
* \brief <h2><b><i>setRotation fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;icine aldigi acilarla matrix icin rotasyon matrisini olusturur.</p>
*
* \param angles[]: angles degerleri.
*/
void Transform::setRotation(double angles[]) {

	transMatrix(0, 0) = (cos(angles[2] * PI / 180) * cos(angles[1] * PI / 180));
	transMatrix(0, 1) = (cos(angles[2] * PI / 180) * sin(angles[1] * PI / 180) * sin(angles[0] * PI / 180)) - (sin(angles[2] * PI / 180) * cos(angles[0] * PI / 180));
	transMatrix(0, 2) = (cos(angles[2] * PI / 180) * sin(angles[1] * PI / 180) * cos(angles[0] * PI / 180)) + (sin(angles[2] * PI / 180) * sin(angles[0] * PI / 180));
	transMatrix(1, 0) = (sin(angles[2] * PI / 180) * cos(angles[1] * PI / 180));
	transMatrix(1, 1) = (sin(angles[2] * PI / 180) * sin(angles[1] * PI / 180) * sin(angles[0] * PI / 180) + (cos(angles[2] * PI / 180) * cos(angles[0] * PI / 180)));
	transMatrix(1, 2) = (sin(angles[2] * PI / 180) * sin(angles[1] * PI / 180) * cos(angles[0] * PI / 180)) - (cos(angles[2] * PI / 180) * sin(angles[0] * PI / 180));
	transMatrix(2, 0) = (-sin(angles[1] * PI / 180));
	transMatrix(2, 1) = (cos(angles[1] * PI / 180) * sin(angles[0] * PI / 180));
	transMatrix(2, 2) = { cos(angles[1] * PI / 180) * cos(angles[0] * PI / 180) };

}
/**
* \brief <h2><b><i>setRotation fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;icine aldigi acilarla matrix icin rotasyon matrisini olusturur.</p>
*
* \param anglesEigen: Eigen::Vector3d
*/
void Transform::setRotation(Eigen::Vector3d anglesEigen) {



	transMatrix(0,0) = (cos(anglesEigen(2) * PI / 180) * cos((anglesEigen(1)) * PI / 180));
	transMatrix(0,1) = (cos(anglesEigen(2) * PI / 180) * sin(anglesEigen(1) * PI / 180) * sin(anglesEigen(0) * PI / 180)) - (sin(anglesEigen(2) * PI / 180) * cos(anglesEigen(0) * PI / 180));
	transMatrix(0,2) = (cos(anglesEigen(2) * PI / 180) * sin(anglesEigen(1) * PI / 180) * cos(anglesEigen(0) * PI / 180)) + (sin(anglesEigen(2) * PI / 180) * sin(anglesEigen(0) * PI / 180));
	transMatrix(1,0) = (sin(anglesEigen(2) * PI / 180) * cos(anglesEigen(1) * PI / 180));
	transMatrix(1,1) = (sin(anglesEigen(2) * PI / 180) * sin(anglesEigen(1) * PI / 180) * sin(anglesEigen(0) * PI / 180) + (cos(anglesEigen(2) * PI / 180) * cos(anglesEigen(0) * PI / 180)));
	transMatrix(1,2) = (sin(anglesEigen(2) * PI / 180) * sin(anglesEigen(1) * PI / 180) * cos(anglesEigen(0) * PI / 180)) - (cos(anglesEigen(2) * PI / 180) * sin(anglesEigen(0) * PI / 180));
	transMatrix(2,0) = (-sin(anglesEigen(1) * PI / 180));
	transMatrix(2,1) = (cos(anglesEigen(1) * PI / 180) * sin(anglesEigen(0) * PI / 180));
	transMatrix(2,2) = { cos(anglesEigen(1) * PI / 180) * cos(anglesEigen(0) * PI / 180) };


}
/**
* \brief <h2><b><i>setTranslation fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;icine aldigi acilarla uzakliklarla beraber 4x4 transMatrix i olusturur </p>
*
* \param transEigen: Eigen::Vector3d
*/
void Transform::setTranslation(Eigen::Vector3d transEigen) {

	
	transMatrix(0,3) = (transEigen(0));
	transMatrix(1,3) = (transEigen(1));
	transMatrix(2,3) = (transEigen(2));
	transMatrix(3,0) = (0);
	transMatrix(3,1) = (0);
	transMatrix(3,2) = (0);
	transMatrix(3,3) = (1);

}
/**
* \brief <h2><b><i>setTranslation fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;icine aldigi acilarla uzakliklarla beraber 4x4 transMatrix i olusturur </p>
*
* \param trans[]: trans degerleri.
*/
void Transform::setTranslation(double transGelen[]) {


	transMatrix(0,3) = (transGelen[0]);
	transMatrix(1,3) = (transGelen[1]);
	transMatrix(2,3) = (transGelen[2]);
	transMatrix(3,0) = (0);
	transMatrix(3,1) = (0);
	transMatrix(3,2) = (0);
	transMatrix(3,3) = (1);

}
/**
* \brief <h2><b><i>doTransform fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;transMatrix le gonderilen nokta carpilarak donusturuluyor </p>
*
* \param p: Point nokta degerleri.
* \return PointCloud:
*/
Point Transform::doTransform(Point p) {
	
	Point pointTMP;

	double xTMP = p.getX();
	double yTMP = p.getY();
	double zTMP = p.getZ();

	Eigen::Vector4d resultPoint;
	Eigen::Vector4d thePoint= { xTMP , yTMP , zTMP , 1 };

	resultPoint = transMatrix * thePoint;
	
	pointTMP.setX(resultPoint(0));
	pointTMP.setY(resultPoint(1));
	pointTMP.setZ(resultPoint(2));
	
	return pointTMP;
}
/**
* \brief <h2><b><i>doTransform fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;icine aldigi PointCloud tan olusturulmus bir nokta bulutunu alip transform islemine tabi tutar ve PointCloud tipinde dondurur. </p>
*
* \param p: Point nokta degerleri.
* \return PointCloudTMP:
*/
PointCloud Transform::doTransform(PointCloud pc) {

	PointCloud PointCloudTMP;

	list <Point> PointLIST = pc.getPoints();
	list <Point> transformList;

	Point pointTMP;

	list <Point>::iterator it;

	for (it = PointLIST.begin(); it != PointLIST.end(); it++)
	{

		pointTMP = doTransform(*it);
		transformList.push_back(pointTMP);

	}

	PointCloudTMP.setPoints(transformList);

	return PointCloudTMP;
	
}