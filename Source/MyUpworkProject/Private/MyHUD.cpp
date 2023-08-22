// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "MyLoginUserWidget.h"
#include "MyRegistrationUserWidget.h"
#include "MyHomeTraineeUserWidget.h"
#include "MyVideoUserWidget.h"

AMyHUD::AMyHUD() {

	//gets reference to all the neccessarry assets
	//and creates the appropriate templetes for all of them
	static ConstructorHelpers::FClassFinder<UMyLoginUserWidget> loginWidgetAsset(TEXT("/Game/Blueprints/MyLoginUserWidget_BP"));
	loginWidgetTemplete = loginWidgetAsset.Class;

	static ConstructorHelpers::FClassFinder<UMyRegistrationUserWidget> registrationWidgetAsset(TEXT("/Game/Blueprints/MyRegistrationUserWidget_BP"));
	registrationWidgetTemplete = registrationWidgetAsset.Class;

	static ConstructorHelpers::FClassFinder<UMyHomeTraineeUserWidget> homeTraineeWidgetAsset(TEXT("/Game/Blueprints/MyHomeTraineeUserWidget_BP"));
	homeTraineeWidgetTemplete = homeTraineeWidgetAsset.Class;

	static ConstructorHelpers::FClassFinder<UMyVideoUserWidget> goToModuleVideoWidgetAsset(TEXT("/Game/Blueprints/MyGoToModuleVideoUserWidget_BP"));
	goToModuleVideoWidgetTemplete = goToModuleVideoWidgetAsset.Class;

	static ConstructorHelpers::FClassFinder<UMyVideoUserWidget> seeReviewVideoWidgetAsset(TEXT("/Game/Blueprints/MySeeReviewVideoUserWidget_BP"));
	seeReviewVideoWidgetTemplete = seeReviewVideoWidgetAsset.Class;
}

void AMyHUD::BeginPlay() {
	Super::BeginPlay();

	//once the level starts the login menu is the first thing to show up
	loginWidget = CreateWidget<UMyLoginUserWidget>(GetWorld(), loginWidgetTemplete);
	loginWidget->AddToViewport();
}

void AMyHUD::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}
//this function gets called when user tries to reach the register menu by clicking on the appropriate button
void AMyHUD::OpenRegistrationWidget() {
	//user can reach the register menu only from login menu
	//it's important to close the login menu so it doesn't block the register menu
	if (loginWidget && loginWidget->GetIsVisible()) {
		loginWidget->RemoveFromViewport();
	}
	//creates the register menu
	registrationWidget = CreateWidget<UMyRegistrationUserWidget>(GetWorld(), registrationWidgetTemplete);
	registrationWidget->AddToViewport();
}

//this function is called when user tries to reach the login menu by clicking on the appropriate button
void AMyHUD::OpenLoginWidget() {
	//player can reach the login menu from register menu
	//it's needed to close the registration menu if that were the case
	if (registrationWidget && registrationWidget->GetIsVisible()) {
		registrationWidget->RemoveFromViewport();
	}

	//loginWidget has created if it hasn't been created yet
	if (loginWidget == nullptr) {
		loginWidget = CreateWidget<UMyLoginUserWidget>(GetWorld(), loginWidgetTemplete);
	}

	//makes the loginWidget visible
	loginWidget->AddToViewport();

}

//this function gets called when user tries to reach the HomeTrainee menu by clicking on the appropriate button
void AMyHUD::OpenHomeTraineeWidget() {
	//this menu can be reached only from login menu
	//that's why it's important to close the login menu before loading this menu
	if (loginWidget && loginWidget->GetIsVisible()) {
		loginWidget->RemoveFromViewport();
	}

	//creates and makes the homeTraineeWidget visible
	homeTraineeWidget = CreateWidget<UMyHomeTraineeUserWidget>(GetWorld(), homeTraineeWidgetTemplete);
	homeTraineeWidget->AddToViewport();
}

//this function gets called when user tries to reach the ModuleVideo menu by clicking on the appropriate button
void AMyHUD::OpenGoToModuleVideo() {
	if (goToModuleVideoWidget == nullptr) {
		goToModuleVideoWidget = CreateWidget<UMyVideoUserWidget>(GetWorld(), goToModuleVideoWidgetTemplete);
	}
	goToModuleVideoWidget->AddToViewport();

}

//this function gets called when user tries to reach the SeeReview menu by clicking on the appropriate button
void AMyHUD::OpenSeeReviewVideo() {
	if (seeReviewVideoWidget == nullptr) {
		seeReviewVideoWidget = CreateWidget<UMyVideoUserWidget>(GetWorld(), seeReviewVideoWidgetTemplete);
	}
	seeReviewVideoWidget->AddToViewport();

}