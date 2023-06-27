// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
class MyLoginUserWidget;
class MyRegistrationUserWidget;
class MyHomeTraineeUserWidget;
class MyVideoUserWidget;
UCLASS()
class MYUPWORKPROJECT_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	

public:

	AMyHUD();

	TSubclassOf<class UUserWidget> loginWidgetTemplete;
	class UMyLoginUserWidget* loginWidget;

	TSubclassOf<class UUserWidget> registrationWidgetTemplete;
	class UMyRegistrationUserWidget* registrationWidget;

	TSubclassOf<class UUserWidget> homeTraineeWidgetTemplete;
	class UMyHomeTraineeUserWidget* homeTraineeWidget;

	TSubclassOf<class UUserWidget> goToModuleVideoWidgetTemplete;
	class UMyVideoUserWidget* goToModuleVideoWidget;

	TSubclassOf<class UUserWidget> seeReviewVideoWidgetTemplete;
	class UMyVideoUserWidget* seeReviewVideoWidget;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void OpenRegistrationWidget();

	void OpenLoginWidget();

	void OpenHomeTraineeWidget();

	void OpenGoToModuleVideo();

	void OpenSeeReviewVideo();
};
