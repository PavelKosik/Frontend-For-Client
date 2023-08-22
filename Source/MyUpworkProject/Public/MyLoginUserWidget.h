// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MyLoginUserWidget.generated.h"

/**
 * 
 */
class MyHUD;
UCLASS()
class MYUPWORKPROJECT_API UMyLoginUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
		void OpenRegistrationMenu();

	UFUNCTION(BlueprintCallable)
		void OpenHomeTraineeMenu();
};
