#include <Event/FTEventDispatcher.h>
#include <gmock/gmock.h>
#include "TestEventDispatcherTypes.h"
#include <Event/FTEventManager.h>
#include "FTEngine.h"
#include <Mock/MockLoader.h>

TEST(TestEventManager, TestRegisterRetrieve) {
    MockLoader mock;

    auto manager = FTEngine::getEventManager();

    auto dispatcher = manager->getEventDispatcher<MockEventDispatcher>();

    EXPECT_NE(dispatcher.get(), nullptr);

    auto dispatcher2 = manager->getEventDispatcher<MockEventDispatcher>();

    EXPECT_EQ(dispatcher.get(), dispatcher2.get());
}

TEST(TestEventManager, TestRegisterDelegate) {
    MockLoader mock;
    auto listener = std::make_shared<MockEventListener1>();

    auto manager = FTEngine::getEventManager();
    auto dispatcher = manager->getEventDispatcher<MockEventDispatcher>();

    manager->registerDelegate<MockEventDispatcher>(listener.get(), &MockEventListener1::callback);

    EXPECT_CALL(*listener, callback(testing::_));

    dispatcher->sendMockEvent1();
}

TEST(TestEventManager, TestUnregisterDelegate) {
    MockLoader mock;

    auto listener = std::make_shared<MockEventListener1>();

    auto manager = FTEngine::getEventManager();
    auto dispatcher = manager->getEventDispatcher<MockEventDispatcher>();

    manager->registerDelegate<MockEventDispatcher>(listener.get(), &MockEventListener1::callback);

    testing::InSequence s;

    EXPECT_CALL(*listener, callback(testing::_));

    dispatcher->sendMockEvent1();

    EXPECT_CALL(*listener, callback(testing::_)).Times(0);

    manager->unregisterDelegate<MockEventDispatcher>(listener.get(), &MockEventListener1::callback);

    dispatcher->sendMockEvent1();
}
