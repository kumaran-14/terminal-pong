/*
 * i_entity.h
 * Defines entity interface
 */

namespace world {

/*
 * Abstract class for all game characters
 */
class IEntity {
public:

    virtual ~IEntity() {}

    /*
     * Update position/dimension using some logic
     */
    virtual void update() = 0;

    /*
     *  Display entity on screen
     */
    virtual void render() = 0;
};

}