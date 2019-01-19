/*
 *  Bullet.hpp
 *
 *  Created on: Jan. 06 2019
 *      Author: Thomas Wiemann
 *
 *  Copyright (c) 2019 Thomas Wiemann.
 *  Restricted usage. Licensed for participants of the course "The C++ Programming Language" only.
 *  No unauthorized distribution.
 */

#ifndef BULLET_HPP_
#define BULLET_HPP_

#include <memory>
#include <thread>
#include "../math/Vector.hpp"
#include "Sphere.hpp"

namespace asteroids
{

/**
 * @brief Renders a Bullet
 */
class Bullet
{

public:

    using Ptr = std::shared_ptr<Bullet>;

    /**
     * @brief Contructor. Build a bullet on the given Fighter's
     *                      position. The bullet will move on the
     *                      given axis.
     * @param   fighter_position   Position of the fighter that shoots this bullet
     * @param   fighter_axis   Axis the bullet will move on
     */
    Bullet(const Vector3f& fighter_position, const Vector3f fighter_axis);

    ~Bullet();

    /**
     * @brief Moves the bullet until it's lifetime is over.
     */
	void run();

	/**
	 * @brief Starts bullet movement
	 */
	void start();


	/*
	 * @brief Stops bullet movement
     */
	void stop();
    
    /**
     * @brief Renders the bullet via glutSolidSphere.
     */
	void render();

    /**
     * @brief Returns the status of this bullet.
     * @return false, if the bullet's lifetime is over and true otherwise
     */
	inline bool isAlive()
    {
        return m_alive;
    };

private:

    //Liftime
    const static int m_lifetime = 900;

    // Tells if bullit is vlaid
    bool m_alive;

    //Axis
    Vector3f m_flightAxis;

    //Spaceship position
    Vector3f m_fighter_position;

    //Tread for bullet
    thread m_thread;

    /// Sphere objet to render the bullet
    Sphere m_sphere;
};

} // namespace asteroids


#endif /* BULLET_HPP_ */
