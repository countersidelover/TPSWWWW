#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyFSM.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
    Idle,
    Move,
    Attack,
    Damage,
    Die,
    Meteor,
    WhiteSphere,
    Charge // ���ο� ���� �߰�
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TPSPROJECT_API UEnemyFSM : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UEnemyFSM();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    void IdleState();
    void MoveState();
    void AttackState();
    void DamageState();
    void DieState();
    void MeteorState();
    void WhiteSphereState();
    void ChargeState(); // ���ο� �Լ� �߰�

    void OnDamageProcess();

    void LaunchMeteors();
    void LaunchWhiteSphere();
    void ChargeWarning(); // ���ο� �Լ� �߰�

    UPROPERTY(EditDefaultsOnly, Category = FSM)
    float idleDelayTime = 2.0f;

    float currentTime = 0;

    UPROPERTY(EditDefaultsOnly, Category = FSM)
    float meteorInterval = 10.0f;

    UPROPERTY(EditDefaultsOnly, Category = FSM)
    float whiteSphereInterval = 15.0f;

    UPROPERTY(EditAnywhere, Category = FSM)
    class ATempMan* target;

    UPROPERTY()
    class AEnemy* me;

    UPROPERTY(EditAnywhere, Category = FSM)
    float attackRange = 150.0f;

    UPROPERTY(EditAnywhere, Category = FSM)
    float attackDelayTime = 2.0f;

    UPROPERTY(EditDefaultsOnly, Category = FSM)
    int32 hp = 3; // BlueprintReadWrite ����

    UPROPERTY(EditAnywhere, Category = FSM)
    float damageDelayTime = 2.0f;

    UPROPERTY(EditAnywhere, Category = FSM)
    float dieSpeed = 50.0f;

    bool bWhiteSphereExecuted;

    UPROPERTY(EditAnywhere, Category = FSM)
    float chargePrepareTime = 3.0f; // �غ� �ð� ����

    UPROPERTY(EditAnywhere, Category = FSM)
    float chargeSpeed = 1000.0f; // ���� �ӵ� �߰�

    EEnemyState mState; // mState ���� �߰�
    UStaticMesh* WhiteSphereMesh; // WhiteSphereMesh ���� �߰�
};
